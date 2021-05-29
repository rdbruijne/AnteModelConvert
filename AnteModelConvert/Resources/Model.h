#pragma once

// Project
#include "Resources/Mesh.h"
#include "Utility/LinearMath.h"
#include "Utility/Utility.h"

namespace ante
{
	class Material;
	class Model
	{
		NO_COPY_ALLOWED(Model)
	public:
		Model() = default;
		explicit Model(const std::string& filePath) : mFilePath(filePath) {}
		explicit Model(const std::string& filePath, int numMeshes) : mFilePath(filePath) { mMeshes.reserve(numMeshes); }

		// info
		const std::string& FilePath() const { return mFilePath; }
		size_t PolyCount() const;
		size_t VertexCount() const;

		// meshes
		size_t MeshCount() const { return mMeshes.size(); }
		const Mesh& GetMesh(size_t index) const { return mMeshes[index]; }
		void AddMesh(const Mesh&& mesh) { mMeshes.push_back(std::move(mesh)); }

	private:
		std::string mFilePath = "";
		std::vector<Mesh> mMeshes;
	};
}
