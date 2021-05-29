// Project
#include "Export/ModelExporter.h"
#include "Import/ModelImporter.h"
#include "Resources/Model.h"
#include "Utility/Logger.h"
#include "Utility/Utility.h"

// C++
#include <iostream>
#include <string>
#include <vector>

// Windows
#include <Windows.h>

namespace
{
	// Console log stream
	class ConsoleLogStream : public ante::Logger::Stream
	{
	public:
		void Write(ante::Logger::Severity severity, const std::string& message) override
		{
			static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(consoleHandle, &info);
			if(msColors.count(severity) != 0)
				SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(msColors[severity]));
			std::cout << message << "\n";
			SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(info.wAttributes & 0xF));
		}

	private:
		inline static int Black   = 0x0;
		inline static int Blue    = 0x1;
		inline static int Green   = 0x2;
		inline static int Red     = 0x4;
		inline static int Intense = 0x8;

		inline static std::map<ante::Logger::Severity, int> msColors =
		{
			{ ante::Logger::Severity::Debug,   Blue | Green },
			//{ ante::Logger::Severity::Info,    Blue | Green | Red},
			{ ante::Logger::Severity::Warning, Green | Red },
			{ ante::Logger::Severity::Error,   Red }
		};
	};



	// Debugger log stream
	class DebuggerLogStream : public ante::Logger::Stream
	{
	public:
		void Write(ante::Logger::Severity /*severity*/, const std::string& message) override
		{
			OutputDebugStringA(message.c_str());
			OutputDebugStringA("\n");
		}
	};



	// File log stream
	class FileLogStream : public ante::Logger::Stream
	{
	public:
		FileLogStream()
		{
			const std::string logFile = ante::ExecutableDirectory() + "\\debug.log";
			fopen_s(&f, logFile.c_str(), "w");
		}

		~FileLogStream()
		{
			fclose(f);
		}

		void Write(ante::Logger::Severity /*severity*/, const std::string& message) override
		{
			fprintf_s(f, "%s\n", message.c_str());
			fflush(f);
		}

	private:
		FILE* f = nullptr;
	};



	void PrintInfo()
	{
		ante::Logger::Info("Ante model converter.");
		ante::Logger::Info("");
		ante::Logger::Info("Arguments:");
		ante::Logger::Info("  Argument    Usage      Description");
		ante::Logger::Info("  --------    -----      -----------");
		ante::Logger::Info("  -o          -o[Dir]    Override output directory (optional)");
		ante::Logger::Info("");
	}
}



int main(int argc, char** argv)
{
	// loggers
	ante::Logger::Attach(std::make_shared<ConsoleLogStream>(), ante::Logger::Severity::All);
	ante::Logger::Attach(std::make_shared<DebuggerLogStream>(), ante::Logger::Severity::All);
	ante::Logger::Attach(std::make_shared<FileLogStream>(), ante::Logger::Severity::All);

	// command line data
	std::string outputDir = "";
	bool printInfo = false;
	std::vector<std::string> inputs;
	inputs.reserve(argc);

	// parse command line
	for(int i = 1; i < argc; i++)
	{
		std::string a(argv[i]);
		if(a.find("-o") == 0)
		{
			outputDir = a.substr(2);
			continue;
		}
		else if(a.find("-?") == 0)
		{
			printInfo = true;
			continue;
		}

		if(ante::FileExists(a))
			inputs.push_back(a);
	}

	// print info
	if(printInfo)
		PrintInfo();

	// convert models
	for (const std::string& i : inputs)
	{
		ante::Logger::Info("Import %s", i.c_str());
		std::shared_ptr<ante::Model> model = ante::ModelImporter::Import(i);

		ante::Logger::Info("Export %s", i.c_str());
		ante::ModelExporter::Export(model, outputDir);

		ante::Logger::Info("");
	}

	ante::Logger::Info("Done!");

	return 0;
}
