#pragma once

// Project
#include "Utility/Utility.h"

// C++
#include <cassert>
#include <string>

namespace ante
{
	class BinaryFile
	{
		NO_COPY_ALLOWED(BinaryFile);

		using StringSizeType = uint32_t;

	public:
		enum class FileMode
		{
			Read,
			Write
		};

		struct Header
		{
			char type[3] = {};
			uint8_t version = 0;
			char exporter[4] = {};
		};

		BinaryFile() = delete;
		explicit BinaryFile(const std::string& path, FileMode mode);
		~BinaryFile();

		// flush to disk
		void Flush();

		// Read
		template<typename TYPE> TYPE Read();
		template<typename TYPE> std::vector<TYPE> ReadVec();

		// Write
		template<typename TYPE> void Write(const TYPE& data);
		template<typename TYPE> void WriteVec(const std::vector<TYPE>& v);

	private:
		void Grow();

		const std::string mPath = "";
		const FileMode mMode;

		size_t mCapacity = 0;
		size_t mHead = 0;
		char* mBuffer = nullptr;
	};
}

#include "BinaryFile.inl"
