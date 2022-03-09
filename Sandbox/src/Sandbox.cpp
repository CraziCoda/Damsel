#include "Damsel.h"
#include <string>

int main() {
	Damsel::Logger logger = Damsel::Logger("SandBox");
	logger.setup("logs.log", "utf-8", Damsel::Logger::Level::INFO);


	Damsel::TimeEvent log_time;

	log_time.setup(&logger, "hello");

	log_time.start_stopwatch();

	logger.fatal("Hello World");
	logger.critical("New World");

	log_time.record_stopwatch();

	logger.warning("Geez");

	log_time.end_stopwatch();
	return 0;
} 