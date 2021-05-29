#pragma once

// Project
#include "Utility/LinearMath.h"
#include "Utility/Utility.h"

// C++
#include <array>
#include <memory>
#include <string>
#include <vector>

namespace ante
{
	class Material;
	class Mesh
	{
	public:
		inline size_t PolygonCount() const { return indices.size(); }
		inline size_t VertexCount() const { return positions.size(); }

		// name
		std::string name = "";

		// positions
		std::vector<float3> positions = {};

		// normals
		std::vector<float3> normals = {};

		// tangents
		std::vector<float3> tangents = {};

		// bitangents
		std::vector<float3> bitangents = {};

		// texcoords
		static constexpr uint32_t MaxTexCoordChannels = 8;
		std::array<std::vector<float3>, MaxTexCoordChannels> texcoords = {};
		std::array<uint32_t, MaxTexCoordChannels> numUvComponents = {};

		// vertex colors
		static constexpr uint32_t MaxColorSets = 8;
		std::array<std::vector<float3>, MaxColorSets> colors = {};

		// faces
		std::vector<uint3> indices = {};

		// material
		std::shared_ptr<Material> material = nullptr;
	};
}
