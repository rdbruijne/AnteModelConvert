#include "ModelImporter.h"

// Project
#include "Resources/Material.h"
#include "Resources/Mesh.h"
#include "Resources/Model.h"
#include "Resources/Texture.h"
#include "Utility/Logger.h"
#include "Utility/Stopwatch.h"
#include "Utility/Utility.h"

// Assimp
#pragma warning(push)
#pragma warning(disable: 4061 4619 26451 26495)
#include "assimp/Importer.hpp"
#include "assimp/DefaultLogger.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#pragma warning(pop)

// C++
#include <filesystem>
#include <iostream>

namespace ante
{
	namespace
	{
		// stream to attach to assimp logger
		class ImportLogStream : public Assimp::LogStream
		{
		public:
			void write(const char* message)
			{
				Logger::Info("[Assimp] %s", message);
			}
		};



		std::shared_ptr<Material> ImportMaterial(const std::string& importDir, const aiMaterial* aMat)
		{
			// name
			aiString name;
			if(aMat->Get(AI_MATKEY_NAME, name) != AI_SUCCESS)
				return nullptr;

			// create material
			std::shared_ptr<Material> mat = std::make_shared<Material>(name.C_Str());

			// #TODO(Rick): parse properties

			return mat;
		}



		void ImportMesh(std::shared_ptr<Model> model, aiMesh* aMesh, const std::vector<std::shared_ptr<Material>>& materials)
		{
			Mesh mesh;
			mesh.name = aMesh->mName.C_Str();
			mesh.material = materials[aMesh->mMaterialIndex];

			// positions
			if(aMesh->mVertices)
			{
				mesh.positions.resize(aMesh->mNumVertices);
				memcpy(mesh.positions.data(), aMesh->mVertices, aMesh->mNumVertices * sizeof(float3));
			}

			// normals
			if(aMesh->mNormals)
			{
				mesh.normals.resize(aMesh->mNumVertices);
				memcpy(mesh.normals.data(), aMesh->mNormals, aMesh->mNumVertices * sizeof(float3));
			}

			// tangents
			if(aMesh->mTangents)
			{
				mesh.tangents.resize(aMesh->mNumVertices);
				memcpy(mesh.tangents.data(), aMesh->mTangents, aMesh->mNumVertices * sizeof(float3));
			}

			// bitangents
			if(aMesh->mBitangents)
			{
				mesh.tangents.resize(aMesh->mNumVertices);
				memcpy(mesh.bitangents.data(), aMesh->mBitangents, aMesh->mNumVertices * sizeof(float3));
			}

			// texcoords
			const size_t maxTexCoordChannels = std::min<uint32_t>(Mesh::MaxTexCoordChannels, AI_MAX_NUMBER_OF_TEXTURECOORDS);
			for(size_t i = 0; i < maxTexCoordChannels; i++)
			{
				if(aMesh->mTextureCoords[i])
				{
					mesh.texcoords[i].resize(aMesh->mNumVertices);
					memcpy(mesh.texcoords[i].data(), aMesh->mTextureCoords[i], aMesh->mNumVertices * sizeof(float3));
				}
			}

			memcpy(mesh.numUvComponents.data(), aMesh->mNumUVComponents, maxTexCoordChannels * sizeof(uint32_t));

			// vertex colors
			const size_t maxColorChannels = std::min<uint32_t>(Mesh::MaxColorSets, AI_MAX_NUMBER_OF_COLOR_SETS);
			for(size_t i = 0; i < maxColorChannels; i++)
			{
				if(aMesh->mColors[i])
				{
					mesh.colors[i].resize(aMesh->mNumVertices);
					memcpy(mesh.colors[i].data(), aMesh->mColors[i], aMesh->mNumVertices * sizeof(float3));
				}
			}

			// indices
			mesh.indices.reserve(aMesh->mNumFaces);
			for(unsigned int i = 0; i < aMesh->mNumFaces; i++)
			{
				aiFace f = aMesh->mFaces[i];
				if(f.mNumIndices != 3)
					Logger::Error("Encountered non-triangulated face during import");
				else
					mesh.indices.push_back(make_uint3(f.mIndices[0], f.mIndices[1], f.mIndices[2]));
			}

			// add the mesh
			model->AddMesh(std::move(mesh));
		}
	}


	const std::vector<FileInfo>& ModelImporter::SupportedFormats()
	{
		static std::vector<FileInfo> result;
		if(result.size() == 0)
		{
			Assimp::Importer importer;
			aiString extensions;
			importer.GetExtensionList(extensions);

			const std::vector<std::string> exts = Split(extensions.C_Str(), ';');
			result.reserve(exts.size());
			for(const std::string& e : exts)
			{
				const std::string ext = e.substr(2);

				FileInfo fi;
				fi.name = ext;
				fi.description = ext;
				fi.ext = ext;
				result.push_back(fi);
			}
		}
		return result;
	}



	bool ModelImporter::Supports(const std::string filePath)
	{
		static std::vector<FileInfo> formats = SupportedFormats();
		const std::string ext = ToLower(FileExtension(filePath).substr(1)); // lowercase extension without dot
		return std::find_if(formats.begin(), formats.end(), [ext](FileInfo fi) { return fi.ext == ext; }) != formats.end();
	}



	std::shared_ptr<Model> ModelImporter::Import(const std::string& filePath)
	{
		Stopwatch sw;
		const std::string globalPath = GlobalPath(filePath);
		const std::string importDir = Directory(globalPath);

		// Importer
		Assimp::Importer importer;
		if(!importer.IsExtensionSupported(FileExtension(globalPath)))
		{
			Logger::Error("Filetype \"%s\" is not supported by the importer.\n", FileExtension(globalPath).c_str());
			return nullptr;
		}

		// import flags
		constexpr uint32_t importFlags =
			//aiProcess_CalcTangentSpace |
			aiProcess_JoinIdenticalVertices |
			//aiProcess_MakeLeftHanded |
			aiProcess_Triangulate |
			aiProcess_RemoveComponent |
			//aiProcess_GenNormals |
			aiProcess_GenSmoothNormals |
			//aiProcess_SplitLargeMeshes |
			aiProcess_PreTransformVertices |
			aiProcess_LimitBoneWeights |
			aiProcess_ValidateDataStructure |
			//aiProcess_ImproveCacheLocality |
			aiProcess_RemoveRedundantMaterials |
			aiProcess_FixInfacingNormals |
			aiProcess_PopulateArmatureData |
			aiProcess_SortByPType |
			aiProcess_FindDegenerates |
			aiProcess_FindInvalidData |
			aiProcess_GenUVCoords |
			//aiProcess_TransformUVCoords |
			//aiProcess_FindInstances |
			aiProcess_OptimizeMeshes |
			//aiProcess_OptimizeGraph |
			//aiProcess_FlipUVs |
			//aiProcess_FlipWindingOrder |
			//aiProcess_SplitByBoneCount |
			//aiProcess_Debone |
			//aiProcess_GlobalScale |
			//aiProcess_EmbedTextures |
			//aiProcess_ForceGenNormals |
			//aiProcess_GenBoundingBoxes |
			0u;
		if(!importer.ValidateFlags(importFlags))
		{
			Logger::Error("Invalid Assimp import flags.");
			return nullptr;
		}

		// assimp properties
		importer.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT);
		importer.SetPropertyInteger(AI_CONFIG_FAVOUR_SPEED, 1);
		importer.SetPropertyInteger(AI_CONFIG_PP_LBW_MAX_WEIGHTS, 4);

		// read the file
		const aiScene* aScene = importer.ReadFile(globalPath.c_str(), importFlags);
		if(!aScene)
		{
			Logger::Error("Failed to import \"%s\": %s", globalPath.c_str(), importer.GetErrorString());
			return nullptr;
		}

		// create model
		std::shared_ptr<Model> model = std::make_shared<Model>(globalPath, aScene->mNumMeshes);

		// import materials
		std::map<std::string, std::shared_ptr<Texture>> textures;
		std::vector<std::shared_ptr<Material>> materials;
		for(uint32_t i = 0; i < aScene->mNumMaterials; i++)
			materials.push_back(ImportMaterial(importDir, aScene->mMaterials[i]));

		// import meshes
		uint32_t polyCount = 0;
		for(uint32_t i = 0; i < aScene->mNumMeshes; i++)
		{
			ImportMesh(model, aScene->mMeshes[i], materials);
			polyCount += aScene->mMeshes[i]->mNumFaces;
		}

		Logger::Info("Imported \"%s\" in %s", globalPath.c_str(), sw.ElapsedString().c_str());
		Logger::Debug("  Meshes   : %s", ThousandSeparators(model->MeshCount()).c_str());
		Logger::Debug("  Materials: %s", ThousandSeparators(materials.size()).c_str());
		//Logger::Debug("  Textures : %s", ThousandSeparators(textures.size()).c_str());
		Logger::Debug("  Polygons : %s", ThousandSeparators(model->PolyCount()).c_str());
		Logger::Debug("  Vertices : %s", ThousandSeparators(model->VertexCount()).c_str());

		return model;
	}
}
