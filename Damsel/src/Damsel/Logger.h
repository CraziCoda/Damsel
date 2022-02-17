#pragma once
#include <iostream>
#include "Core.h"
#include <string>
#include <ctime>
#include <fstream>

namespace Damsel {
	class DAMSEL_API  Logger
	{
	public:
		Logger();
		Logger(const std::string& name);
		~Logger();


		const std::string& getName();

		enum class Level { ALL, INFO = 1, WARNING, ERROR, CRITICAL, FATAL };

		void setup(const std::string& file, const std::string& encoding, Level level = Level::ALL);
		const std::string& getLogPath();
		const std::string& getEncoding();
		int getLogLevel();

		//Logging Functions
		void info(char* message);
		void warning(char* message);
		void error(char* message);
		void critical(char* message);
		void fatal(char* message);




	private:
		std::string m_Name;
		std::string log_path;
		std::string encoding_type;
		const std::string time_format;
		std::string pattern = "[%H:%M:%S] %n: %m";
		int log_level;
		time_t currentTime;
		struct tm* localTime;

		void log(char* message, int level);

		// Time Functions
		void getCurrentTime();
		int getYear();
		int getMonth();
		int getDay();
		int getHour();
		int getMinute();
		int getSecond();


		// Setting Message Pattern
		void setPattern(char* pattern);
		const std::string getLogMessage(char* message);
		std::string patternCommand(int char_code, char* message);

		// Using File System
		void writeToFile(const std::string& file, const std::string& message);
	};
}