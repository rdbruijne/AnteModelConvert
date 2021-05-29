#pragma once

// Project

// C++
#include <string>

namespace ante
{
	class Material
	{
	public:
		// construction
		explicit Material(const std::string& name);

		const std::string& Name() const { return mName; }

	private:
		std::string mName = "";
	};
}
