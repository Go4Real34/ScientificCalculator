#pragma once
#include <string>
class ScientificCalculator {
public:
	ScientificCalculator() = default;
	~ScientificCalculator() = default;
	void setValue1(double value);
	void setValue2(double value);

	// Functions for arithmetic operations
	double add() const;
	double subtract() const;

	// Function to get the result
	double getResult() const;

	// Function to perform operation
	void performOperation(int operation);


private:
	double value1;
	double value2;


	double result;
};


double getValidDoubleInput(const std::string& prompt);