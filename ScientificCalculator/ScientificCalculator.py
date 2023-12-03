import math

def calculator():
    print("Select operation:\n")
    print("\t 1. Arithmetic\n"
          "\t 2. Trigonometric\n"
          "\t 3. Logarithmic\n"
          "\t 4. Advanced Operations\n")

    choice = input("Enter choice (1, 2, 3 or 4): ")
    print("")
    if choice == '1':
        perform_arithmetic_operation()
    elif choice == '2':
        perform_trigonometric_operation()
    elif choice == '3':
        perform_logarithmic_operation()
    elif choice == '4':
        perform_advanced_operation()
    else:
        print("Invalid choice. Please enter 1, 2, 3 or 4.")
        calculator()


def perform_arithmetic_operation():
    try:
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        perform_arithmetic_operation()

    operator = input("Enter arithmetic operator (+, -, *, /): ")

    if operator == '+':
        result = num1 + num2
    elif operator == '-':
        result = num1 - num2
    elif operator == '*':
        result = num1 * num2
    elif operator == '/':
        if num2 != 0:
            result = num1 / num2
        else:
            print("Error: Cannot divide by zero.")
            return
    else:
        print("Invalid operator. Please enter +, -, *, or /.")
        perform_arithmetic_operation()
        return

    print(f"Result: {result}")
    print("\nExiting from the calculator...")
def perform_trigonometric_operation():
    try:
        num = float(input("Enter the angle in degrees: "))
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        perform_trigonometric_operation()
    print("")
    print("Select trigonometric function:")
    print("")
    print("\t 1. Sine\n"
          "\t 2. Cosine\n"
          "\t 3. Tangent\n")

    trig_choice = input("Enter choice (1, 2, or 3): ")

    if trig_choice == '1':
        result = math.sin(math.radians(num))
    elif trig_choice == '2':
        result = math.cos(math.radians(num))
    elif trig_choice == '3':
        result = math.tan(math.radians(num))
    else:
        print("Invalid choice. Please enter 1, 2, or 3.")
        perform_trigonometric_operation()
        return

    result = round(result, 6)
    print(f"Result: {result}")
    print("\nExiting from the calculator...")
def perform_logarithmic_operation():
    try:
        num = float(input("Enter the number for logarithmic operation: "))
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        perform_logarithmic_operation()

    base = float(input("Enter the base for logarithmic operation: "))

    if num > 0 and base > 0 and base != 1:
        result = math.log(num, base)
        result = round(result, 6)
        print(f"Result: {result}")
    else:
        print("Invalid input. Please ensure that both the number and base are positive, and the base is not equal to 1.")
        perform_logarithmic_operation()
    print("\nExiting from the calculator...")
def perform_advanced_operation():
    print("Select advanced operation:\n")
    print("\t 1. Exponential\n"
          "\t 2. Square Root\n"
          "\t 3. Power\n"
          "\t 4. Factorial\n"
          "\t 5. Absolute\n"
          "\t 6. Multiplicative Inverse\n"
          "\t 7. Square\n"
          "\t 8. Power of Ten\n"
          "\t 9. Log Base Ten\n")

    adv_choice = input("Enter choice (1-9): ")

    if adv_choice == '1':
        num = float(input("Enter the number for exponential operation: "))
        result = math.exp(num)
    elif adv_choice == '2':
        num = float(input("Enter the number for square root operation: "))
        if num >= 0:
            result = math.sqrt(num)
        else:
            print("Invalid input. Square root of a negative number is undefined.")
            return
    elif adv_choice == '3':
        try:
            base = float(input("Enter the base for power operation: "))
            exponent = float(input("Enter the exponent for power operation: "))
        except ValueError:
            print("Invalid input. Please enter valid numbers.")
            perform_advanced_operation()
            return
        result = math.pow(base, exponent)
    elif adv_choice == '4':
        try:
            num = int(input("Enter a non-negative integer for factorial operation: "))
        except ValueError:
            print("Invalid input. Please enter a valid non-negative integer.")
            perform_advanced_operation()
            return
        if num >= 0:
            result = math.factorial(num)
        else:
            print("Invalid input. Factorial of a negative number is undefined.")
            return
    elif adv_choice == '5':
        num = float(input("Enter the number for absolute operation: "))
        result = abs(num)
    elif adv_choice == '6':
        num = float(input("Enter the number for multiplicative inverse operation: "))
        if num != 0:
            result = 1 / num
        else:
            print("Error: Cannot calculate multiplicative inverse of zero.")
            return
    elif adv_choice == '7':
        num = float(input("Enter the number for square operation: "))
        result = num ** 2
    elif adv_choice == '8':
        exponent = float(input("Enter the exponent for power of ten operation: "))
        result = 10 ** exponent
    elif adv_choice == '9':
        num = float(input("Enter the number for log base ten operation: "))
        if num > 0:
            result = math.log10(num)
        else:
            print("Invalid input. Please enter a positive number for log base ten operation.")
            return
    else:
        print("Invalid choice. Please enter a number between 1 and 9.")
        perform_advanced_operation()
        return
    result = round(result, 6)
    print(f"Result: {result}")
    print("\nExiting from the calculator...")
# Run the calculator
calculator()