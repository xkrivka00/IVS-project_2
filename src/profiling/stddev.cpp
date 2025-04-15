/**
 * @file        stddev.cpp
 * @author      Václav Semerád
 * @date        13.04.2025
 * @brief       Program for calculating the standard deviation of input numbers.
 *
 * This program reads real numbers from standard input, calculates their average,
 * and then computes the standard deviation using an external library functions
 * from our 'mathlib.h'.
 *
 * @return Returns 0 when success, 1 if not (less then 2 numbers on input, wrong file, ...)
 *
 * @see ../mathlib.h
 */

 #include "../mathlib.h"
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <vector>
 
 #define FIRST_ARG 1
 
 int main(){
     std::vector<double> numbers; ///< Container to store input numbers
     double number;
     double sum = 0;
 
    // Read real numbers from standard input
     while (scanf("%lf", &number) == 1) {
         numbers.push_back(number);
         sum += number;
     }
 
     unsigned int count = numbers.size();

     // Check if there are enough numbers to compute standard deviation
     if (count <= 1) {
         std::cerr << "Invalid input.\n";
         return 1;
     }
 
    // Calculate arithmetic mean
     double average = sum / count;
     double sum_of_squared_diffs = 0;
 
    // Get sum of squared differences 
     for (int index = 0; index < count; index++){
         double difference = numbers[index] - average;
         sum_of_squared_diffs += difference * difference;
     }
 
     // Calculate sample standard deviation
     double result = sum_of_squared_diffs / (count - 1);
     result = mathlib::square_root(result, 2);
     std::cout << result << std::endl;
     return 0;
 }

 /** END OF FILE STDDEV.CPP*/