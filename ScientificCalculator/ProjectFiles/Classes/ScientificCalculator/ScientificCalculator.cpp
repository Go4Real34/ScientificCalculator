#include <iostream>
#include <string>
#include <sstream>

#include "ScientificCalculator.h"

bool ScientificCalculator::getNumberValues() {
	return getNumberValue(true) && getNumberValue(false);
}

bool ScientificCalculator::getNumberValue(const bool& isFirst) {
	std::string line = "";
	while (true) {
		std::cout << "Enter " << (isFirst ? "first" : "second") << " value (q/Q to cancel): ";
		std::getline(std::cin, line);
		if (line == "q" || line == "Q") {
			std::cout << std::endl;
			return false;
		}

		std::istringstream iss(line);
		if (iss >> (isFirst ? this -> value1 : this -> value2)) {
			return true;
		} else {
			std::cout << "Invalid input. Please enter a valid number." << std::endl << std::endl;
			continue;
		}
	}
}
