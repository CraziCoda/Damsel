#include "Logger.h"



namespace Damsel {
	Logger::Logger() : m_Name("root"), log_level(0) { getCurrentTime(); }

	Logger::Logger(const std::string& name) : m_Name(name), log_level(0) { getCurrentTime(); }

	Logger::~Logger() {}

	void Logger::setup(const std::string& file, const std::string& encoding, Logger::Level level)
	{
		log_level = int(level);
		log_path = file;
		encoding_type = encoding;
	}

	const std::string& Logger::getName() { return m_Name; }

	const std::string& Logger::getLogPath() { return log_path; }

	const std::string& Logger::getEncoding() { return encoding_type; }

	int Logger::getLogLevel() { return log_level; }

	//Logging
	void Logger::log (std::string msg, Logger::Level level)
	{
		const char* str = msg.c_str();
		char* cstr = new char[msg.length() + 1];
		strcpy(cstr, str);

		std::cout << getLogMessage(cstr) << std::endl;

		writeToFile(log_path, getLogMessage(cstr));
	}

	//Overload of log for timing
	void Logger::log(std::chrono::duration<double> record, int type, const std::string& name)
	{
		double rec;
		switch (type) {
		case 1:
			std::cout << name << " Started: 0.00000000" << std::endl;
			writeToFile(log_path, name + " Started: 0.00000000");
			break;
		case 2:
			std::cout << name << ": Time elapsed: " << record.count() << std::endl;
			rec = record.count();
			writeToFile(log_path, name +" : Time elapsed: " + std::to_string(rec));
			break;
		case 3:
			std::cout << name <<": Ended with time elapse: " << record.count() << std::endl;
			rec = record.count();
			writeToFile(log_path, name + " : Time elapsed: " + std::to_string(rec));
			break;
		}

	}

	//Time Functions
	void Logger::getCurrentTime()
	{
		time(&currentTime);
		localTime = localtime(&currentTime);
	}
	int Logger::getYear()
	{
		getCurrentTime();
		return 1900 + localTime->tm_year;
	}
	int Logger::getMonth()
	{
		getCurrentTime();
		return localTime->tm_mon + 1;
	}
	int Logger::getDay()
	{
		getCurrentTime();
		return localTime->tm_mday;
	}
	int Logger::getHour()
	{
		getCurrentTime();
		return localTime->tm_hour;
	}
	int Logger::getMinute()
	{
		getCurrentTime();
		return localTime->tm_min;
	}
	int Logger::getSecond()
	{
		getCurrentTime();
		return localTime->tm_sec;
	}

	// Set Pattern
	void Logger::setPattern(char* pattern) { this->pattern = pattern; }

	const std::string Logger::getLogMessage(char* message)
	{
		std::string new_message = "";
		for (int i = 0; i < pattern.size(); i++)
		{
			if (int(pattern[i]) == 37)
			{
				i++;
				int char_code = pattern[i];
				new_message += patternCommand(char_code, message);	
			}
			else
			{
				new_message += pattern[i];
			}
		}
		return new_message;
	}

	std::string Logger::patternCommand(int char_code, char* message)
	{
		switch (char_code) {
		case 72:
			return std::to_string(getHour());
		case 77:
			return std::to_string(getMinute());
		case 83:
			return std::to_string(getMinute());
		case 110:
			return m_Name;
		case 109:
			return message;
		default:
			return "";
		}
	}

	void Logger::writeToFile(const std::string& file, const std::string& message)
	{
		std::fstream file_handler;

		file_handler.open(file, std::ios::app);
		if (file_handler.is_open())
		{
			file_handler << message << "\n";
		}

		file_handler.close();
	}

	void TimeEvent::setup(Logger* logger, const std::string& name)
	{
		this->logger = logger;
		this->name_o = name;
	}

	void TimeEvent::start_stopwatch()
	{
		stopwatch_start = std::chrono::system_clock::now();
		logger->log(stopwatch_start - stopwatch_end, 1, name_o);
	}
	void TimeEvent::record_stopwatch()
	{
		stopwatch_record = std::chrono::system_clock::now();
		logger->log(stopwatch_record - stopwatch_start, 2, name_o);

	}
	void TimeEvent::end_stopwatch()
	{
		stopwatch_end = std::chrono::system_clock::now();
		logger->log(stopwatch_end - stopwatch_start, 2, name_o);

		stopwatch_start = std::chrono::system_clock::from_time_t(0);

	}

}