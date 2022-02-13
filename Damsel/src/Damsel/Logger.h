#pragma once
#include <iostream>
#include "Core.h"
#include <string>

namespace Damsel {
	class DAMSEL_API  Logger
	{
	public:
		Logger();
		Logger(const std::string& name);
		~Logger();

		

		const std::string& getName();

		enum class Level { INFO = 1, WARNING, ERROR, CRITICAL, FATAL };

		void setup(const std::string& file, const std::string& encoding, Level level);
		const std::string& getLogPath();
		const std::string& getEncoding();
		int getLogLevel();

		void info(char* message);
		void warning(char* message);
		void error(char* message); 
		void critical(char* message);
		void fatal(char* message);

	private:
		std::string m_Name;
		std::string log_path;
		std::string encoding_type;
		int log_level;

		void log(char* message, int level);
	};

}