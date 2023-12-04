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
			MENU_CHOICES_EXIT = 0,

			ADD = 1,
			SUBSTRACT = 2,
			MULTIPLY = 3,
			DIVIDE = 4,
			MODULUS = 5,
			EXPONENT = 6,
			FACTORIAL = 7,
			ABSOLUTE = 8,
			ADDITIVE_INVERSE = 9,
			MULTIPLICATIVE_INVERSE = 10,
			SQUARE = 11,
			SQUARE_ROOT = 12,
			POWER = 13,
			POWER_OF_TEN = 14,
			LOGARITHM_WITH_BASE_TEN = 15,
			LOGARITHM_WITH_BASE_E = 16,
			LOGARITHM_WITH_BASE_N = 17,
			SINE = 18,

			MENU_CHOICES_LENGTH = 19
		};

		const long double PI = 3.14159265358979323846L;

		const enum AngleTypes {
			ANGLE_TYPES_EXIT = 0,

			DEGREE = 1,
			RADIAN = 2,
			GRADIAN = 3,

			ANGLE_TYPES_LENGTH = 4
		};
		
		AngleTypes angleIndex = AngleTypes::DEGREE;

		void add();
		void substract();
		void multiply();
		bool divide();
		bool modulus();
		void exponent();
		bool factorial();
		void absolute();
		void additiveInverse();
		bool multiplicativeInverse();
		void square();
		bool squareRoot();
		void power();
		void powerOfTen();
		bool logarithmWithBaseTen();
		bool logarithmWithBaseE();
		bool logarithmWithBaseN();
		void sine();

		void printResult(const MenuChoices& operationIndex) const;
		bool executeOperation(const MenuChoices& operationIndex);
		
		MenuChoices getMenuChoice() const;
		void convertToRadian();
		bool getAngleType();
		
		bool getNumberValues();
		bool getNumberValue(const std::string& isFirst);
};
