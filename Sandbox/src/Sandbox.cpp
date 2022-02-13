#include "Damsel.h"

int main() {
	Damsel::Logger logger = Damsel::Logger("main");
	logger.setup("logs.log", "utf-8", Damsel::Logger::Level::INFO);
	logger.fatal("Hello world");
	return 0;
} 