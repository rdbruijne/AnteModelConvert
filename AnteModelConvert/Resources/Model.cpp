#include "Model.h"

// Project
#include "Material.h"

namespace ante
{
	size_t Model::PolyCount() const
	{
		size_t count = 0;
		for(const Mesh& m : mMeshes)
			count += m.PolygonCount();
		return count;
	}



	size_t Model::VertexCount() const
	{
		size_t count = 0;
		for(const Mesh& m : mMeshes)
			count += m.VertexCount();
		return count;
	}
}
