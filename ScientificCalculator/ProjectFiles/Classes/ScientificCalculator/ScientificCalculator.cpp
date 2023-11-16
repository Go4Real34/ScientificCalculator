#include <iostream>
#include <string>
#include <sstream>

#include "ScientificCalculator.h"

bool ScientificCalculator::executeOperation(const MenuChoices& operationIndex) const {
	switch (operationIndex) {
		case MenuChoices::EXIT: {
			std::cout << "Thanks for using our Scientific Calculator." << std::endl;
			std::cout << "Exiting from the calculator..." << std::endl;
			return false;
		}
		
		default: {
			std::cout << "Invalid operation index. Please enter a valid operation in the menu." << std::endl << std::endl;
			return false;
		}
	}
}

ScientificCalculator::MenuChoices ScientificCalculator::getMenuChoice() const {
	std::string line = "";

	while (true) {
		std::cout << "Please select an operation from the menu below." << std::endl;
		std::cout << "[0] - Quit" << std::endl;
		std::cout << "Choice: ";
		std::getline(std::cin, line);
		std::cout << std::endl;

		std::istringstream iss(line);
		int choice = 0;
		if (iss >> choice) {
			if (choice >= static_cast<int>(this -> MenuChoices::EXIT) && 
				choice <= static_cast<int>(this -> MenuChoices::LENGTH - 1)) {
				return static_cast<MenuChoices>(choice);
			} else {
				std::cout << "Invalid menu option. Please enter a valid menu option." << std::endl << std::endl;
				continue;
			}
		} else {
			std::cout << "Invalid input. Please enter a valid number." << std::endl << std::endl;
			continue;
		}
	}
}

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
