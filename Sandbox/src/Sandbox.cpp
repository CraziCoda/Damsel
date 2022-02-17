#include "Damsel.h"

int main() {
	Damsel::Logger logger = Damsel::Logger("SandBox");
	logger.setup("logs.log", "utf-8", Damsel::Logger::Level::INFO);
	logger.fatal("Hello 1");
	logger.error("Hello 2");
	for (int i = 0; i < 100; i++)
	{
		logger.info("Hello World");
	}
	return 0;
} 