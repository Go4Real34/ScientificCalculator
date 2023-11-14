#include "C:\Users\PC\Documents\C++Projects\ScientificCalculator\ScientificCalculator\Class\ScientificCalculator.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

void ScientificCalculator::setValue1(double value) {
    value1 = value;
}

void ScientificCalculator::setValue2(double value) {
    value2 = value;
}
double ScientificCalculator::getResult() const {
    return result;
}

void ScientificCalculator::performOperation(int operation) {
    while (true) {
        switch (operation) {
        case 1:
            result = add();
            return; // Exit the loop on successful operation

        case 2:
            result = subtract();
            return; // Exit the loop on successful operation

        default:
            std::cout << "Invalid operation selected. Please enter 1 for addition or 2 for subtraction: ";
            std::cin >> operation;
            break;
        }
    }
}

double ScientificCalculator::add() const {
    return value1 + value2;
}

double ScientificCalculator::subtract() const {
    return value1 - value2;
}


double getValidDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        // Check if the user wants to quit
        if (input == "q" || input == "Q") {
            std::cout << "Quitting the program. Goodbye!\n";
            exit(0);
        }

        // Use stringstream to convert input to a double
        std::istringstream iss(input);
        if (iss >> value) {
            return value;  // Valid input, return the double value
        }
        else {
            std::cout << "Wrong input. Please enter a valid double or 'q' to quit.\n";
        }
    }
}
