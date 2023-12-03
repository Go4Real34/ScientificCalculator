#include <iostream>
#include <string>
#include <sstream>

#include "ScientificCalculator.h"

void ScientificCalculator::add() {
	this -> result = this -> value1 + this -> value2;
	return;
}

void ScientificCalculator::substract() {
	this -> result = this -> value1 - this -> value2;
	return;
}

void ScientificCalculator::multiply() {
	this -> result = this -> value1 * this -> value2;
	return;
}

bool ScientificCalculator::divide() {
	if (this -> value2 != 0) {
		this -> result = this -> value1 / this -> value2;
		return true;
	} else {
		std::cout << std::endl;
		std::cout << "Division by zero detected." << std::endl;
		std::cout << "Please enter a valid number for divisor." << std::endl;
		return false;
	}
}

bool ScientificCalculator::modulus() {
	if (this -> value2 != 0) {
		this -> result = this -> value1;
		while (this -> result >= this -> value2) {
			this -> result -= this -> value2;
		}
		return true;
	} else {
		std::cout << std::endl;
		std::cout << "Division by zero detected." << std::endl;
		std::cout << "Please enter a valid number for divisor." << std::endl;
		return false;
	}
	return;
}

void ScientificCalculator::printResult(const MenuChoices& operationIndex) const {
	std::cout << "Result: ";
	switch (operationIndex) {
		case MenuChoices::ADD: {
			std::cout << this -> value1 << " + " << this -> value2;
			break;
		}
		
		case MenuChoices::SUBSTRACT: {
			std::cout << this -> value1 << " - " << this -> value2;
			break;
		}
		
		case MenuChoices::MULTIPLY: {
			std::cout << this -> value1 << " * " << this -> value2;
			break;
		}
		
		case MenuChoices::DIVIDE: {
			std::cout << this -> value1 << " / " << this -> value2;
			break;
		}
		
		case MenuChoices::MODULUS: {
			std::cout << this -> value1 << " % " << this -> value2;
			break;
		}
		
		case MenuChoices::EXIT: {
			break;
		}
		
		default: {
			break;
		}
	}
	std::cout << " = " << this -> result << std::endl;
}

bool ScientificCalculator::executeOperation(const MenuChoices& operationIndex) {
	bool shouldPrintResult = true;
	switch (operationIndex) {
		case MenuChoices::ADD: {
			if (!this -> getNumberValues()) {
				return true;
			}
			this -> add();
			break;
		}
		
		case MenuChoices::SUBSTRACT: {
			if (!this -> getNumberValues()) {
				return true;
			}
			this -> substract();
			break;
		}
		
		case MenuChoices::MULTIPLY: {
			if (!this -> getNumberValues()) {
				return true;
			}
			this -> multiply();
			break;
		}
		
		case MenuChoices::DIVIDE: {
			if (!this -> getNumberValues()) {
				return true;
			}
			shouldPrintResult = this -> divide();
			break;
		}
		
		case MenuChoices::MODULUS: {
			if (!this -> getNumberValues()) {
				return true;
			}
			shouldPrintResult = this -> modulus();
			break;
		}
		
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

	if (shouldPrintResult) {
		std::cout << std::endl;
		this -> printResult(operationIndex);
	}

	return true;
}

ScientificCalculator::MenuChoices ScientificCalculator::getMenuChoice() const {
	std::string line = "";

	while (true) {
		std::cout << "Please select an operation from the menu below." << std::endl;
		std::cout << "[1] - Add" << std::endl;
		std::cout << "[2] - Substract" << std::endl;
		std::cout << "[3] - Multiply" << std::endl;
		std::cout << "[4] - Divide" << std::endl;
		std::cout << "[5] - Modulus" << std::endl;

		std::cout << std::endl;
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
	if (!getNumberValue(true) || !getNumberValue(false)) {
		std::cout << "Couldn't get values. Process cancelled." << std::endl << std::endl;
		return false;
	}
	return true;
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
