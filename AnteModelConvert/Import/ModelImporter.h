#pragma once

// Project
#include "Import/FileInfo.h"

// C++
#include <memory>
#include <string>
#include <vector>

namespace ante
{
	class Model;
	class ModelImporter
	{
	public:
		static const std::vector<FileInfo>& SupportedFormats();
		static bool Supports(const std::string filePath);

		static std::shared_ptr<Model> Import(const std::string& filePath);
	};
}
