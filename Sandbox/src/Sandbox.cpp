#include "Damsel.h"

int main() {
	Damsel::Logger car = Damsel::Logger("jeff");
	Damsel::Logger dog = Damsel::Logger("Dog");
	std::cout << car.GetName()<< std::endl;
	std::cout << dog.GetName();
	return 0;
}