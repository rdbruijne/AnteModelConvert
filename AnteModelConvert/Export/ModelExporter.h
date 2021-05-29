#pragma once

// Project
#include "Import/FileInfo.h"

// C++
#include <memory>
#include <string>

namespace ante
{
	class Model;
	class ModelExporter
	{
	public:
		static bool Export(std::shared_ptr<Model> model, const std::string& outputDirectory);
	};
}
