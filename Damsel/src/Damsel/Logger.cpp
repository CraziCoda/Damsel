#include "Logger.h"

namespace Damsel {
	Logger::Logger(): m_Name("root"), log_level(0) {}

	Logger::Logger(const std::string& name): m_Name(name), log_level(0) {
	}
	Logger::~Logger(){}

	void Logger::setup(const std::string& file, const std::string& encoding, Logger::Level level){
		log_level = int(level);
		log_path = file;
		encoding_type = encoding;
	}
	const std::string& Logger::getName() { return m_Name; }

	const std::string& Logger::getLogPath() { return log_path; }

	const std::string& Logger::getEncoding() { return encoding_type; }

	int Logger::getLogLevel() { return log_level; }

	void Logger::info(char* message){
		Logger::Level level { Logger::Level::INFO };
		this->log(message, int(level));
	}

	void Logger::warning(char* message) {
		Logger::Level level{ Logger::Level::WARNING };
		this->log(message, int(level));
	}

	void Logger::error(char* message) {
		Logger::Level level{ Logger::Level::ERROR };
		this->log(message, int(level));
	}

	void Logger::critical(char* message) {
		Logger::Level level{ Logger::Level::CRITICAL };
		this->log(message, int(level));
	}

	void Logger::fatal(char* message) {
		Logger::Level level{ Logger::Level::FATAL };
		this->log(message, int(level));
	}

	void Logger::log(char* message, int level){
		std::cout << level << " " << message << std::endl;
	}

}