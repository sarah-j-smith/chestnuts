#include <iostream>
#include <math.h>

#include <limits>

bool isIntegral(double x) {
    // EPSILON is a very small number 1.19209290e-7F - representing double 
    // floating point accuracy. There are 3 terms in the equation, so it can only
    // be accurate to 3 * epsilon or 0.00000003 or so.
    return abs(x - trunc(x)) < 3 * std::numeric_limits<double>::epsilon();
}

bool isPowerOf(int x, int b) {
    // Is there an integral number y which is the number of times to 
    // multiply 3 by itself, such that the result is exactly x? 
    //
    //     pow(3, y) == x : x in Z (set of integers) 
    //
    // The pow() functions compute x raised to the power y. So how do
    // we reverse the pow() function? Answer - logarithms.
    // 
    // Log y to base a of a number x is:
    //
    //    the power a must be raised by to equal x 
    //
    // ...is saying the same thing as...
    //
    //        log-a (x) = y
    //  =>    pow(a, x) = y
    //
    // There's no log() function with two arguments though. Damn.
    //
    // We have C functions for log-10 and log-e.  To find log of an
    // arbitrary base-z where we know the logs to other base b,
    // must use "change of base" rule - formula (for b == 10):
    //
    //     log-z (x) = log-10(x) / log-10(z)
    // 
    // or we can use natural log ln, the log to base magic number "e"
    // which is the c function log() instead of log-10:
    //
    //     log-z (x) = log(x) / log(z)
    //
    // If the answer is an integral number then that is a power.
    return isIntegral( log(x) / log(b) );
}

/** 
 * Find if given number x is a power of three. Return true if it is,
 * and false otherwise.
 */
bool isPowerOfThree(double x) {

    return isPowerOf(x, 3);
}


int main(int argc, char * argv[]) {
    int num = 125;
    int base = 5;
    std::cin >> num;
    std::cin >> base;
    if (num > 0) {
        std::cout << (isPowerOf( double(num), double(base) ) ? "true" : "false" ) << std::endl; 
    } else {
        std::cerr << "Could not parse a number from input" << std::endl;
    }
}
