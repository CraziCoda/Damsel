#pragma once
#include <iostream>
#include "Core.h"
#include <string>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include "sstream"
#include <chrono>


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
		const std::string& getLogPath ();
		const std::string& getEncoding();
		int getLogLevel();

		template<typename T>
		void info(T	 message)
		{
			std::stringstream strm;
			std::string msg;

			strm << message;
			log(strm.str(), Level::INFO);
			
		}

		template<typename T>
		void warning(T message)
		{
			std::stringstream strm;
			std::string msg;

			strm << message;

			log(strm.str(), Level::WARNING);

		}

		template<typename T>
		void error(T	 message)
		{
			std::stringstream strm;
			std::string msg;

			strm << message;
			log(strm.str(), Level::ERROR);

		}
	
		template<typename T>
		void critical(T	 message)
		{
			std::stringstream num;
			std::stringstream strm;
			std::string msg;

			strm << message;

			log(strm.str(), Level::CRITICAL);

		}

		template<typename T>
		void fatal(T	 message)
		{
			std::stringstream strm;
			std::string msg;

			strm << message;
			log(strm.str(), Level::FATAL);

		}

		//Overload for timing
		void log(std::chrono::duration<double> record, int type, const std::string& name);
	private:
		std::string m_Name;
		std::string log_path;
		std::string encoding_type;
		const std::string time_format;
		std::string pattern = "[%H:%M:%S] %n: %m";
		int log_level;
		time_t currentTime;
		struct tm* localTime;


		//Logging
		void log(const std::string msg, Level level);

		


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

	class DAMSEL_API TimeEvent {
	public:
		void setup(Logger* logger, const std::string& name);
		void start_stopwatch();
		void record_stopwatch();
		void end_stopwatch();

		

	private:
		
		std::string name_o;
		Logger* logger;

		using TimePoint = std::chrono::time_point<std::chrono::system_clock,
			std::chrono::duration<double>>;
		TimePoint stopwatch_start;
		TimePoint stopwatch_end;
		TimePoint stopwatch_record;
	};
}