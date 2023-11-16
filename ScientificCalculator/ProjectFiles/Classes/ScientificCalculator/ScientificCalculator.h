#pragma once

class ScientificCalculator {
	public:
		ScientificCalculator() = default;
		~ScientificCalculator() = default;

	private:
		long double value1 = 0;
		long double value2 = 0;

		long double result = 0;

		const enum MenuChoices {
			EXIT = 0,

			ADD = 1,
			SUBSTRACT = 2,

			LENGTH = 3
		};

		void add();
		void substract();

		void printResult(const MenuChoices& operationIndex) const;
		bool executeOperation(const MenuChoices& operationIndex);
		MenuChoices getMenuChoice() const;

		bool getNumberValues();
		bool getNumberValue(const bool& isFirst);
};
