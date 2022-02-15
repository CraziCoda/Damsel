#include "Damsel.h"

int main() {
	Damsel::Logger logger = Damsel::Logger("SandBox");
	logger.setup("logs.log", "utf-8", Damsel::Logger::Level::INFO);
	logger.fatal("Hello world");
	return 0;
} 