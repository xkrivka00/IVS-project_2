/**
 * @file        tests.cpp
 * @author      Václav Semerád, VUT FIT Brno, xsemerv00@fit.vutbr.cz
 * @date        26.03.2025
 *
 * @brief       Tests of math library
 *
 */

#include <gtest/gtest.h>
#include "../mathlib.h"

//Temporary run: g++ tests.cpp -o tests -lgtest -lgtest_main -pthread
//               ./tests

TEST(Calculator, Add){
    EXPECT_EQ(mathlib::addition(1,1), 2);
    EXPECT_EQ(mathlib::addition(10, 15), 25);
    EXPECT_EQ(mathlib::addition(1000, 2000), 3000);

    EXPECT_EQ(mathlib::addition(5000000, 2500000), 7500000);
    EXPECT_EQ(mathlib::addition(1000000, 2000000), 3000000);
    EXPECT_EQ(mathlib::addition(500000000, 250000000), 750000000);

    EXPECT_EQ(mathlib::addition(-2, -3), -5);
    EXPECT_EQ(mathlib::addition(-10, -15), -25);
    EXPECT_EQ(mathlib::addition(-20, -30), -50);
    EXPECT_EQ(mathlib::addition(-100, -150), -250);
    EXPECT_EQ(mathlib::addition(5, -3), 2);
    EXPECT_EQ(mathlib::addition(-71, 42), -29);

    EXPECT_EQ(mathlib::addition(0, 5), 5);
    EXPECT_EQ(mathlib::addition(7, 0), 7);
    EXPECT_EQ(mathlib::addition(0, 0), 0);

    EXPECT_DOUBLE_EQ(mathlib::addition(1.5, 2.5), 4.0);
    EXPECT_DOUBLE_EQ(mathlib::addition(-1.2, -3.8), -5.0);
    EXPECT_DOUBLE_EQ(mathlib::addition(2, -2.565), -0.565);
    EXPECT_DOUBLE_EQ(mathlib::addition(2.5, -2.5), 0.0);

    EXPECT_DOUBLE_EQ(mathlib::addition(1000000.0, 2000000.0), 3000000.0);
    EXPECT_DOUBLE_EQ(mathlib::addition(-500000.0, -500000.0), -1000000.0);
    EXPECT_DOUBLE_EQ(mathlib::addition(12345678.9, 87654321.1), 100000000.0);
    EXPECT_DOUBLE_EQ(mathlib::addition(-9876543.2, 9876543.2), 0.0);

    EXPECT_NE(mathlib::addition(0, 0), 5);
    EXPECT_NE(mathlib::addition(321321, 989423), 5321);
    EXPECT_NE(mathlib::addition(-32132189321, -76321), 58);
    EXPECT_NE(mathlib::addition(0, -32645654123), 0);
}

TEST(Calculator, Subtract){
    EXPECT_EQ(mathlib::subtraction(10, 5), 5);
    EXPECT_EQ(mathlib::subtraction(20, 5), 15);
    EXPECT_EQ(mathlib::subtraction(30, 15), 15);

    EXPECT_DOUBLE_EQ(mathlib::subtraction(10.0, 10.0), 0.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(500.0, 500.0), 0.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(10.0, -5.0), 15.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(100.0, -50.0), 150.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(-10.0, -5.0), -5.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(-20.0, -10.0), -10.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(5.0, 10.0), -5.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(50.0, 100.0), -50.0);

    EXPECT_DOUBLE_EQ(mathlib::subtraction(5.123456, 3.123456), 2.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(0.333333, 0.123333), 0.210000);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(0.0, 100.0), -100.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(100.0, 0.0), 100.0);

    EXPECT_DOUBLE_EQ(mathlib::subtraction(1000000.0, 500000.0), 500000.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(10000000.0, 9999999.0), 1.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(-5.0, 5.0), -10.0);
    EXPECT_DOUBLE_EQ(mathlib::subtraction(5.0, -5.0), 10.0);

    EXPECT_NE(mathlib::subtraction(0, 0), 5);
    EXPECT_NE(mathlib::subtraction(321321, 989423), 5321);
    EXPECT_NE(mathlib::subtraction(-32132189321, -76321), 58);
    EXPECT_NE(mathlib::subtraction(0, -32645654123), 0);
}

TEST(Calculator, Multiply){
    EXPECT_EQ(mathlib::multiplication(2, 3), 6);
    EXPECT_EQ(mathlib::multiplication(5, 4), 20);
    EXPECT_EQ(mathlib::multiplication(10, 10), 100);
    EXPECT_EQ(mathlib::multiplication(0, 5), 0);
    EXPECT_EQ(mathlib::multiplication(5, 0), 0);
    EXPECT_EQ(mathlib::multiplication(0, 0), 0);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(-2.0, 3.0), -6.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(5.0, -4.0), -20.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(-3.0, -7.0), 21.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(1.0, 5.0), 5.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(5.0, 1.0), 5.0);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(100000.0, 1000.0), 100000000.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(100000000.0, 1000000.0), 1e14);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(1.5, 2.5), 3.75);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(1e-5, 1e-6), 1e-11);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(1e-9, 1e-9), 1e-18);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(1e9, 1e-9), 1.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(1e18, 1e-18), 1.0);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(-5.0, 0.5), -2.5);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(-1.0, 1e-3), -1e-3);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(1000.0, 1e-3), 1.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(0.5, 1e-5), 5e-6);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(-1.5, 2.0), -3.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(2.5, -2.0), -5.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(-1.5, -2.0), 3.0);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(-2.5, -4.0), 10.0);

    EXPECT_DOUBLE_EQ(mathlib::multiplication(-1000000.0, 1000.0), -1e9);
    EXPECT_DOUBLE_EQ(mathlib::multiplication(-1000000.0, -1000.0), 1e9);

    EXPECT_NE(mathlib::multiplication(-5.0, 0.5), -2.5321321);
    EXPECT_NE(mathlib::multiplication(-1.0, 1e-3), 0);
}

TEST(Calculator, Division){
    EXPECT_EQ(mathlib::division(4, 2), 2);
    EXPECT_EQ(mathlib::division(10, 4), 2.5);
    EXPECT_EQ(mathlib::division(40, 8), 5);
    EXPECT_EQ(mathlib::division(1, 1), 1);
    EXPECT_EQ(mathlib::division(0, 332321), 0);  

    EXPECT_EQ(mathlib::division(4, -2), -2);
    EXPECT_EQ(mathlib::division(-10, -4), 2.5);
    EXPECT_EQ(mathlib::division(40, -8), -5);
    EXPECT_EQ(mathlib::division(-1, 1), -1);
    EXPECT_EQ(mathlib::division(0, -332321), 0);  

    EXPECT_EQ(mathlib::division(1500, 1), 1500);
    EXPECT_EQ(mathlib::division(10000, 10), 1000);
    EXPECT_EQ(mathlib::division(9000000003, 3), 3000000001);
    EXPECT_EQ(mathlib::division(1, 1000000), 0.000001); 

    EXPECT_NEAR(mathlib::division(1e-9, 2), 5e-10, 1e-12);
    EXPECT_NEAR(mathlib::division(1, 1e9), 1e-9, 1e-12);

    EXPECT_ANY_THROW(mathlib::division(1, 0));
}

TEST(Calculator, Factorial){
    mathlib m;
    EXPECT_EQ(m.factorial(0), 1);
    EXPECT_EQ(m.factorial(2), 2);
    EXPECT_EQ(m.factorial(3), 6);
    EXPECT_EQ(m.factorial(4), 24);
    EXPECT_EQ(m.factorial(5), 120);
    
    EXPECT_ANY_THROW(m.factorial(13));
    EXPECT_ANY_THROW(m.factorial(-43712));
    EXPECT_ANY_THROW(m.factorial(12.345));
    EXPECT_ANY_THROW(m.factorial(-2.345));
}

TEST(Calculator, Power){
    EXPECT_EQ(mathlib::power(1, 1), 1);
    EXPECT_EQ(mathlib::power(0, 13213), 0);
    EXPECT_EQ(mathlib::power(2, 3), 8);
    EXPECT_EQ(mathlib::power(3, 2), 9);
    EXPECT_EQ(mathlib::power(10, 2), 100);

    EXPECT_EQ(mathlib::power(6, 3), 216);
    EXPECT_EQ(mathlib::power(8, 4), 4096);
    EXPECT_EQ(mathlib::power(11, 2), 121);
    EXPECT_EQ(mathlib::power(12, 3), 1728);
    EXPECT_EQ(mathlib::power(13, 2), 169);
    EXPECT_EQ(mathlib::power(15, 3), 3375);
    EXPECT_EQ(mathlib::power(20, 2), 400);

    EXPECT_ANY_THROW(mathlib::power(8, -1));
    EXPECT_ANY_THROW(mathlib::power(18, -132));
    EXPECT_ANY_THROW(mathlib::power(84, -12));
}

TEST(Calculator, Root){
    EXPECT_EQ(mathlib::root(2, 1), 1);
    EXPECT_EQ(mathlib::root(3201, 0), 0);
    EXPECT_EQ(mathlib::root(2, 4), 2);
    EXPECT_EQ(mathlib::root(3, 8), 2);
    EXPECT_EQ(mathlib::root(2, 100), 10);

    EXPECT_EQ(mathlib::root(2, 1000000), 1000);

    EXPECT_NEAR(mathlib::root(2, 2), 1.414, 1e-3);
    EXPECT_NEAR(mathlib::root(2, 3), 1.732, 1e-3);
    EXPECT_NEAR(mathlib::root(2, 5), 2.236, 1e-3);
    EXPECT_NEAR(mathlib::root(2, 50), 7.071, 1e-3);

    EXPECT_ANY_THROW(mathlib::root(1.1, 8));
    EXPECT_ANY_THROW(mathlib::root(2, -4));
    EXPECT_ANY_THROW(mathlib::root(-2, 4));
}

TEST(Calculator, Loagrithm){
    EXPECT_EQ(mathlib::decadic_logarithm(10), 1);
    EXPECT_EQ(mathlib::decadic_logarithm(100), 2);
    EXPECT_EQ(mathlib::decadic_logarithm(1000), 3);
    EXPECT_EQ(mathlib::decadic_logarithm(10000), 4);
    EXPECT_EQ(mathlib::decadic_logarithm(100000), 5);
    EXPECT_EQ(mathlib::decadic_logarithm(1000000), 6);

    EXPECT_NEAR(mathlib::decadic_logarithm(2), 0.301, 1e-3);
    EXPECT_NEAR(mathlib::decadic_logarithm(5), 0.699, 1e-3);
    EXPECT_NEAR(mathlib::decadic_logarithm(50), 1.699, 1e-3);
    EXPECT_NEAR(mathlib::decadic_logarithm(500), 2.699, 1e-3);

    EXPECT_ANY_THROW(mathlib::decadic_logarithm(0));
    EXPECT_ANY_THROW(mathlib::decadic_logarithm(-1));
    EXPECT_ANY_THROW(mathlib::decadic_logarithm(-32183712));
}
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/**END OF FILE */