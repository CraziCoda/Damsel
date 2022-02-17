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

	void Logger::info(char* message)
	{
		Logger::Level level{ Logger::Level::INFO };
		this->log(message, int(level));
	}

	void Logger::warning(char* message)
	{
		Logger::Level level{ Logger::Level::WARNING };
		this->log(message, int(level));
	}

	void Logger::error(char* message)
	{
		Logger::Level level{ Logger::Level::ERROR };
		this->log(message, int(level));
	}

	void Logger::critical(char* message)
	{
		Logger::Level level{ Logger::Level::CRITICAL };
		this->log(message, int(level));
	}

	void Logger::fatal(char* message)
	{
		Logger::Level level{ Logger::Level::FATAL };
		this->log(message, int(level));
	}

	void Logger::log(char* message, int level)
	{
		auto message_l = getLogMessage(message);
		std::cout << message_l << std::endl;
		writeToFile(log_path, message_l);
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
			if (int(pattern[i]) == 37) {
				int char_code = pattern[i + 1];
				new_message += patternCommand(char_code, message);
				i++;
			}
			else {
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
}