/**
 * @file        stddev.cpp
 * @author      Václav Semerád
 * @date        13.04.2025
 * @brief       Program for calculating the standard deviation of input numbers.
 *
 * This program reads real numbers from standard input, calculates their average,
 * and then computes the standard deviation using library functions from our 'mathlib.h'.
 *
 * @return Returns 0 when success, 1 if not (less than 2 numbers on input, wrong file, ...)
 *
 * @see ../mathlib.h
 */

 #include "../mathlib.h"
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <vector>
 
 #define FIRST_ARG 1
 
 /**
  * @brief Computes the sample standard deviation of a list of real numbers.
  *
  * This function uses the mathlib library to perform arithmetic operations such as
  * addition, subtraction, multiplication, division, and square root calculation.
  * The computation follows the sample standard deviation formula:
  *
  * \f[
  *     s = \sqrt{\frac{1}{n - 1} \sum_{i=1}^{n} (x_i - \bar{x})^2}
  * \f]
  *
  * @param numbers A vector containing the real numbers to process.
  * @return The sample standard deviation of the numbers.
  */
 double compute_stddev(const std::vector<double>& numbers) {
     unsigned int count = numbers.size();
     double sum = 0;
 
     for (auto num : numbers) {
         sum = mathlib::addition(sum, num);
     }
 
     /// Calculate arithmetic mean
     double average = mathlib::division(sum, count);
     double sum_of_squared_diffs = 0;
 
     /// Get sum of squared differences
     for (auto num : numbers) {
         double diff = mathlib::subtraction(num, average);
         sum_of_squared_diffs += mathlib::multiplication(diff, diff);
     }
     
     /// Calculate sample standard deviation
     double result_before_div = mathlib::division(sum_of_squared_diffs, (count - 1));
     return mathlib::root(2, result_before_div);
 }
 
 /**
  * @brief Main entry point of the program.
  *
  * Reads real numbers from standard input, checks for valid input length,
  * and prints the computed standard deviation to standard output.
  *
  * @return 0 if successful, 1 if there are not enough valid inputs.
  */
 int main() {
     std::vector<double> numbers; ///< Container to store input numbers
     double number;
 
     /// Read real numbers from standard input
     while (scanf("%lf", &number) == 1) {
         numbers.push_back(number);
     }
 
     /// Check if there are enough numbers to compute standard deviation
     if (numbers.size() <= 1) {
         std::cerr << "Invalid input.\n";
         return 1;
     }
 
     /// Calculate the standard deviation
     double result = compute_stddev(numbers);
     std::cout << result << std::endl;
     return 0;
 }
 
 /** END OF FILE STDDEV.CPP */
 