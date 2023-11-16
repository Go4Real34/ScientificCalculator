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

			LENGTH = 1
		};

		MenuChoices getMenuChoice() const;

		bool getNumberValues();
		bool getNumberValue(const bool& isFirst);
};
