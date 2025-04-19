/**
 * @file        mathlib.h
 * @author      Václav Semerád, VUT FIT Brno, xsemerv00@fit.vutbr.cz
 * @date        27.03.2025
 *
 * @brief       Implementation of math library
 */

#include <cmath>
#include <iostream>
#include <stdexcept>

/**
 * @class mathlib
 * @brief A static math library providing basic mathematical operations.
 */
class mathlib
{
public:
    /**
     * @brief Adds two numbers.
     * @param num1 First number.
     * @param num2 Second number.
     * @return Sum of num1 and num2.
     */

    static double addition(double num1, double num2)
    {
        return num1 + num2;
    }

    /**
     * @brief Subtracts the second number from the first.
     * @param num1 First number.
     * @param num2 Second number.
     * @return Difference of num1 and num2.
     */

    static double subtraction(double num1, double num2)
    {
        return num1 - num2;
    }

    /**
     * @brief Multiplies two numbers.
     * @param num1 First number.
     * @param num2 Second number.
     * @return Product of num1 and num2.
     */

    static double multiplication(double num1, double num2)
    {
        return num1 * num2;
    }

    /**
     * @brief Divides the first number by the second.
     * @param num1 Numerator.
     * @param num2 Denominator (must not be zero).
     * @return Quotient of num1 and num2.
     * @throws std::runtime_error if num2 is zero.
     */

    static double division(double num1, double num2)
    {
        if (num2 == 0)
            throw std::runtime_error("Can't divide by zero");
        return num1 / num2;
    }

    /**
     * @brief Computes the factorial of a number.
     * @param num1 Factorial algument (must be a non-negative integer and <= 12).
     * @return Factorial of num1.
     * @throws std::runtime_error if num1 is negative, non-integer, or greater than 12.
     */
    static int factorial(double num)
    {
        if (num < 0 || num - static_cast<int>(num) != 0) // Safer with fp precision
        {
            throw std::runtime_error("Factorials can only be of natural numbers");
        }

        int n = static_cast<int>(num);
        if (n > 12)
        {
            throw std::runtime_error("Too big, sorry");
        }

        int result = 1;
        for (int i = 2; i <= n; ++i)
        {
            result *= i;
        }

        return result;
    }

    /**
     * @brief Computes the power of a base raised to an exponent.
     * @param base The base number.
     * @param exponent The exponent (must be a non-negative integer).
     * @return base raised to the power of exponent.
     * @throws std::runtime_error if exponent is negative.
     */

    static double power(double base, double exponent)
    {
        
        if (exponent < 0 || exponent - static_cast<int>(exponent) != 0)
        {
            throw std::runtime_error("Exponent can be only natural number or zero");
        }
        if (base == 0)
        {
            return 0;
        }
        if (base == 1)
        {
            return 1;
        }
        if (exponent == 0)
        {
            return 1;
        }
        double result = 1;
        for (int iter = 0; iter < exponent; iter++)
        {
            result *= base;
        }
        return result;
    }

    /**
     * @brief Computes the n-th root of a base.
     * @param base The base number.
     * @param degree The degree of the root (must be a natural number greater than 1).
     * @return The n-th root of base.
     * @throws std::runtime_error if degree is not a natural number > 1 or if base is negative with an even degree.
     */

    static double root(double base, double degree)
    {
        // Resolve non-natural numbers and degree zero
        if (degree <= 1 || degree - static_cast<int>(degree) != 0)
        {
            throw std::runtime_error("Degree of a root must be a natural number");
        }
        if (base == 0)
        {
            return 0;
        }

        int deg = int(degree);
        if (base < 0 && deg % 2 == 0)
        {
            throw std::runtime_error("Even roots of negative numbers are not real");
        }
        if (base < 0 && deg % 2 != 0)
        {
            return -pow(-base, 1.0 / deg);
        }
        return pow(base, 1.0 / deg);
    }

    /**
     * @brief Computes the base-10 logarithm of a number.
     * @param number The number (must be greater than 0).
     * @return Base-10 logarithm of the number.
     * @throws std::runtime_error if number is less than or equal to zero.
     */

    static double decadic_logarithm(double number)
    {
        if (number <= 0)
        {
            throw std::runtime_error("Root must be greater than 0");
        }
        return log10(number);
    }
};

/** END OF FILE MATHLIB.H*/
