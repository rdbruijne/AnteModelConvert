#pragma once

// c++
#include <string>
#include <vector>

#define NO_COPY_ALLOWED(c)				\
	c(const c&) = delete;				\
	c& operator =(const c&) = delete;

namespace ante
{
	// string manipulation
	std::string format(const char* fmt, ...);
	std::string ToLower(const std::string& str);
	std::string ToUpper(const std::string& str);
	std::vector<std::string> Split(const std::string& str, char delimiter);
	std::string ReplaceAll(const std::string& str, const std::string& toReplace, const std::string& replaceStr);

	// file paths
	std::string Directory(const std::string& filePath);
	std::string FileName(const std::string& filePath);
	std::string FileExtension(const std::string& filePath);
	std::string FileNameWithoutExtension(const std::string& filePath);

	// path locations
	std::string ExecutableDirectory();
	std::string CurrentDirectory();
	std::string GlobalPath(const std::string& path);
	std::string RelativeFilePath(const std::string& path);

	// file handling
	std::string ReadFile(const std::string filePath);
	void WriteFile(const std::string filePath, const std::string& text);
	bool FileExists(const std::string& filePath);

	uint64_t FileCreateTime(const std::string& filePath);
	uint64_t FileLastAccessTime(const std::string& filePath);
	uint64_t FileLastWriteTime(const std::string& filePath);
	uint64_t FileSize(const std::string& filePath);

	// stringify
	std::string TimeString(int64_t elapsedNs);
	std::string ThousandSeparators(uint64_t val, const std::string& separator = ",");

	// mark variables as used
	inline void MarkVariablesUsed(...) {}

	// error handling
	void FatalError(const char* fmt, ...);
}
