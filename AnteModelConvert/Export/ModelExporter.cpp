#include "ModelExporter.h"

// Project
#include "Export/BinaryFile.h"
#include "Resources/Material.h"
#include "Resources/Model.h"
#include "Utility/Logger.h"
#include "Utility/Stopwatch.h"

// model file format can be found at:
// https://gitlab.com/TropicalTrevor/ante/-/blob/master/FILE_FORMATS.md

// semantics
#define POSITION		0
#define NORMAL			1
#define TANGENT			2
#define TEXCOORD0		3
#define TEXCOORD1		4
#define TEXCOORD2		5
#define TEXCOORD3		6
#define TEXCOORD4		7
#define TEXCOORD5		8
#define TEXCOORD6		9
#define TEXCOORD7		10
#define BLENDINDICES	11
#define BLENDWEIGHT		12
#define COLOR0			13
// COLOR<i> = COLOR0 + i

// mesh file header
#define MESH_FILE_ID		{ 'M', 'S', 'H' }
#define MESH_FILE_VERSION	0
#define MESH_FILE_EXPORTER	{ 'C', 'O', 'N', 'V' }

namespace ante
{
	bool ModelExporter::Export(std::shared_ptr<Model> model, const std::string& outputDirectory)
	{
		Stopwatch sw;

		// file path
		const std::string dir = outputDirectory.empty() ? Directory(model->FilePath()) : outputDirectory;
		const std::string fileName = FileNameWithoutExtension(model->FilePath()) + ".mesh";

		BinaryFile bf(dir + "\\" + fileName, BinaryFile::FileMode::Write);

		// header
		const BinaryFile::Header header = { MESH_FILE_ID, MESH_FILE_VERSION, MESH_FILE_EXPORTER };
		bf.Write(header);

		// mesh count
		bf.Write(static_cast<uint32_t>(model->MeshCount()));

		// write meshes
		for(size_t meshIx = 0; meshIx < model->MeshCount(); meshIx++)
		{
			// fetch mesh
			const Mesh& mesh = model->GetMesh(meshIx);

			// mesh name
			bf.Write(mesh.name);

			// material name
			bf.Write(mesh.material->Name());

			// gather attributes
			struct Attribute
			{
				uint32_t id;
				uint32_t numFloats;
				const std::vector<float3>& data;
			};
			std::vector<Attribute> attributes;

			auto addAttrib = [&attributes, mesh](const std::vector<float3>& data, uint32_t id, uint32_t numFloats)
			{
				if(data.size() > 0)
					attributes.push_back({id, numFloats, data});
			};
			addAttrib(mesh.positions, POSITION, 3);
			addAttrib(mesh.normals, NORMAL, 3);
			addAttrib(mesh.tangents, TANGENT, 3);

			for(uint32_t i = 0; i < Mesh::MaxTexCoordChannels; i++)
				addAttrib(mesh.texcoords[i], TEXCOORD0 + i, mesh.numUvComponents[i]);

			for(uint32_t i = 0; i < Mesh::MaxColorSets; i++)
				addAttrib(mesh.colors[i], TEXCOORD0 + i, 3);

			// write attributes
			bf.Write(static_cast<uint32_t>(attributes.size()));

			size_t floatCount = 0;
			for(const Attribute& attrib : attributes)
			{
				bf.Write(attrib.id);
				bf.Write(attrib.numFloats);
				floatCount += attrib.numFloats;
			}

			// number of floats in the interleaved vertex buffer
			bf.Write(static_cast<uint32_t>(mesh.VertexCount() * floatCount));

			// number of ints in the index buffer
			bf.Write(static_cast<uint32_t>(mesh.PolygonCount() * 3));

			// interleave vertex data
			for(size_t i = 0; i < mesh.VertexCount(); i++)
			{
				for(Attribute& attrib : attributes)
				{
					if(attrib.numFloats == 1)
						bf.Write(attrib.data[i].x);
					else if(attrib.numFloats == 2)
						bf.Write(make_float2(attrib.data[i]));
					else if(attrib.numFloats == 3)
						bf.Write(attrib.data[i]);
				}
			}

			// write indices
			for(const uint3& ix : mesh.indices)
				bf.Write(ix);
		}

		Logger::Info("Exported \"%s\" in %s", (dir + "\\" + fileName).c_str(), sw.ElapsedString().c_str());

		return true;
	}
}
