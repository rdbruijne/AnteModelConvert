#include "Utility.h"

// Project
#include "Utility/Logger.h"

// C++
#include <algorithm>
#include <assert.h>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

// Windows
#include <shlwapi.h>
#include <Windows.h>

namespace ante
{
	std::string format(const char* fmt, ...)
	{
		// format message
		size_t n = strlen(fmt);
		int final_n = -1;

		std::unique_ptr<char[]> formatted;
		va_list ap;
		do
		{
			n <<= 1;
			formatted.reset(new char[n + 1]);
			va_start(ap, fmt);
			final_n = vsnprintf_s(formatted.get(), n - 1, n - 2, fmt, ap);
			va_end(ap);
		} while(final_n < 0);

		return std::string(formatted.get());
	}



	std::string ToLower(const std::string& str)
	{
		std::string s = str;
		std::transform(s.begin(), s.end(), s.begin(), [](char c)
		{
			return static_cast<char>(std::tolower(c));
		});
		return s;
	}



	std::string ToUpper(const std::string& str)
	{
		std::string s = str;
		std::transform(s.begin(), s.end(), s.begin(), [](char c)
		{
			return static_cast<char>(std::toupper(c));
		});
		return s;
	}



	std::vector<std::string> Split(const std::string& str, char delimiter)
	{
		std::vector<std::string> result;
		std::string token;
		std::istringstream tokenStream(str);
		while (std::getline(tokenStream, token, delimiter))
			result.push_back(token);
		return result;
	}



	std::string ReplaceAll(const std::string& str, const std::string& toReplace, const std::string& replaceStr)
	{
		std::string localStr = str;
		size_t pos = localStr.find(toReplace);
		while(pos != std::string::npos)
		{
			localStr.replace(pos, toReplace.size(), replaceStr);
			pos = localStr.find(toReplace, pos + replaceStr.size());
		}
		return localStr;
	}



	std::string Directory(const std::string& filePath)
	{
		std::string folderPath = filePath;
		folderPath = folderPath.substr(0, folderPath.find_last_of('/'));
		folderPath = folderPath.substr(0, folderPath.find_last_of('\\'));
		return folderPath;
	}



	std::string FileName(const std::string& filePath)
	{
		std::string fileName = filePath;
		size_t i = fileName.find_last_of('/');
		if(i != std::string::npos)
			fileName = fileName.substr(i + 1);

		i = fileName.find_last_of('\\');
		if(i != std::string::npos)
			fileName = fileName.substr(i + 1);

		return fileName;
	}



	std::string FileExtension(const std::string& filePath)
	{
		const std::string fileName = FileName(filePath);
		const size_t dotIx = fileName.find_last_of('.');
		return dotIx == std::string::npos ? "" : fileName.substr(dotIx);
	}



	std::string FileNameWithoutExtension(const std::string& filePath)
	{
		const std::string fileName = FileName(filePath);
		return fileName.substr(0, fileName.find_last_of('.'));
	}



	std::string ExecutableDirectory()
	{
		char path[MAX_PATH] = {};
		GetModuleFileNameA(NULL, path, MAX_PATH);
		return Directory(path);
	}



	std::string CurrentDirectory()
	{
		char path[MAX_PATH] = {};
		GetCurrentDirectoryA(MAX_PATH, path);
		return std::string(path) + "\\";
	}



	std::string GlobalPath(const std::string& path)
	{
		char globalPath[MAX_PATH] = {};
		GetFullPathNameA(path.c_str(), MAX_PATH, globalPath, NULL);
		return strlen(globalPath) == 0 ? path : globalPath;
	}



	std::string RelativeFilePath(const std::string& path)
	{
		char relPath[MAX_PATH] = {};
		PathRelativePathToA(relPath, CurrentDirectory().c_str(), 0, path.c_str(), FILE_ATTRIBUTE_NORMAL);
		return strlen(relPath) == 0 ? path : relPath;
	}



	std::string ReadFile(const std::string filePath)
	{
		std::ifstream fileStream(filePath);
		assert(fileStream.is_open());
		if(!fileStream.is_open())
			return "";

		fileStream.seekg(0, std::ios::end);
		const size_t fileSize = static_cast<size_t>(fileStream.tellg());
		fileStream.seekg(0, std::ios::beg);

		std::string fileContent;
		fileContent.reserve(fileSize);
		fileContent.assign(std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>());

		return fileContent;
	}



	void WriteFile(const std::string filePath, const std::string& text)
	{
		std::ofstream fileStream;
		fileStream.open(filePath, std::ofstream::out | std::ofstream::trunc);
		assert(fileStream.is_open());
		fileStream.write(text.c_str(), static_cast<std::streamsize>(text.length()));
	}



	bool FileExists(const std::string& filePath)
	{
		DWORD fileAttrib = GetFileAttributesA(filePath.c_str());
		return (fileAttrib != INVALID_FILE_ATTRIBUTES && !(fileAttrib & FILE_ATTRIBUTE_DIRECTORY));
	}



	uint64_t FileCreateTime(const std::string& filePath)
	{
		WIN32_FILE_ATTRIBUTE_DATA info = {};
		if(!GetFileAttributesExA(filePath.c_str(), GetFileExInfoStandard, &info))
			return 0;
		return static_cast<uint64_t>(info.ftCreationTime.dwHighDateTime) << 32 | static_cast<uint64_t>(info.ftCreationTime.dwLowDateTime);
	}



	uint64_t FileLastAccessTime(const std::string& filePath)
	{
		WIN32_FILE_ATTRIBUTE_DATA info = {};
		if(!GetFileAttributesExA(filePath.c_str(), GetFileExInfoStandard, &info))
			return 0;
		return static_cast<uint64_t>(info.ftLastAccessTime.dwHighDateTime) << 32 | static_cast<uint64_t>(info.ftLastAccessTime.dwLowDateTime);
	}



	uint64_t FileLastWriteTime(const std::string& filePath)
	{
		WIN32_FILE_ATTRIBUTE_DATA info = {};
		if(!GetFileAttributesExA(filePath.c_str(), GetFileExInfoStandard, &info))
			return 0;
		return static_cast<uint64_t>(info.ftLastWriteTime.dwHighDateTime) << 32 | static_cast<uint64_t>(info.ftLastWriteTime.dwLowDateTime);
	}



	uint64_t FileSize(const std::string& filePath)
	{
		WIN32_FILE_ATTRIBUTE_DATA info = {};
		if(!GetFileAttributesExA(filePath.c_str(), GetFileExInfoStandard, &info))
			return 0;
		return static_cast<uint64_t>(info.nFileSizeHigh) << 32 | static_cast<uint64_t>(info.nFileSizeLow);
	}



	std::string TimeString(int64_t elapsedNs)
	{
		if(elapsedNs < 1'000)
			return format("%lld ns", elapsedNs);
		if(elapsedNs < 1'000'000)
			return format("%lld.%01lld us", elapsedNs / 1'000, (elapsedNs / 100) % 10);
		if(elapsedNs < 1'000'000'000)
			return format("%lld.%01lld ms", elapsedNs / 1'000'000, (elapsedNs / 100'000) % 10);
		if(elapsedNs < 60'000'000'000)
			return format("%lld.%01lld s", elapsedNs / 1'000'000'000, (elapsedNs / 100'000'000) % 10);

		// (hh:)mm:ss format
		const int64_t t2 = elapsedNs / 1'000'000'000;
		if(t2 < 3600)
			return format("%02lld:%02lld", t2 / 60, t2 % 60);
		return format("%lld:%02lld:%02lld", t2 / 3600, (t2 % 3600) / 60, t2 % 60);
	}



	std::string ThousandSeparators(uint64_t val, const std::string& separator)
	{
		if(val < 1000)
			return std::to_string(val);

		std::string s = "";
		int i = 0;
		while(val > 0)
		{
			if(i && (i % 3) == 0)
				s = separator + s;
			s = "0123456789"[val % 10] + s;
			val /= 10;
			i++;
		}
		return s;
	}



	void FatalError(const char* fmt, ...)
	{
		// format message
		size_t n = strlen(fmt);
		int final_n = -1;

		std::unique_ptr<char[]> formatted;
		va_list ap;
		do
		{
			n <<= 1;
			formatted.reset(new char[n + 1]);
			va_start(ap, fmt);
			final_n = vsnprintf_s(formatted.get(), n - 1, n - 2, fmt, ap);
			va_end(ap);
		} while(final_n < 0);

		// handle error
		Logger::Error(formatted.get());
		MessageBoxA(NULL, formatted.get(), "Fatal Error", MB_OK | MB_ICONERROR);
		assert(false);
		exit(EXIT_FAILURE);
	}
}
