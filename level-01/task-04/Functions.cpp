#include <iostream>

// Function prototypes
double add(double a, double b);       // Function to perform addition
double subtract(double a, double b);  // Function to perform subtraction
double multiply(double a, double b);  // Function to perform multiplication
double divide(double a, double b);    // Function to perform division

int main()
{
    double num1 = 0, num2 = 0;

    // Get input from user
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Perform arithmetic operations and display results
    std::cout << "Sum: " << add(num1, num2) << std::endl;
    std::cout << "Difference: " << subtract(num1, num2) << std::endl;
    std::cout << "Product: " << multiply(num1, num2) << std::endl;
    std::cout << "Quotient: " << divide(num1, num2) << std::endl;

    return 0;
}

// Function to perform addition
double add(double a, double b)
{
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b)
{
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b)
{
    return a * b;
}

// Function to perform division
double divide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    } else
    {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0; // Returning 0 for division by zero, can be customized based on requirements
    }
}
