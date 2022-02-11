#include "Logger.h"

namespace Damsel {
	Logger::Logger(): m_Name("root") {}
	Logger::Logger(const std::string& name): m_Name(name) {
		
	}
	Logger::~Logger(){}

	void Logger::setup(std::string file, std::string encoding, int level){
		std::cout << "Hello World \n";
	}
	const std::string& Logger::GetName() { return m_Name; }
}	