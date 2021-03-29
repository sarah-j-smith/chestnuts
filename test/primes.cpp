#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

// Input an integer N and then input N integers p to test if they are prime.
//
// A prime is a natural number greater than 1 that has no positive divisors 
// other than 1 and itself. 
//
// Given each number, p, find and print whether it is Prime or Not Prime.
//
// Note that 1 is not prime, and 2 is prime. Negative numbers cannot 
// be prime, but negative inputs are out of scope.

TEST_CASE("testing 1 is not prime") {

    std::vector<std::string> input_lines = {
        "1",
        "1"
    };
    auto output_lines = runprog("../primes/primes", input_lines);

    CHECK(output_lines[0] == "Not Prime");
}

TEST_CASE("testing 2 is prime") {

    std::vector<std::string> input_lines = {
        "1",
        "2"
    };
    auto output_lines = runprog("../primes/primes", input_lines);

    CHECK(output_lines[0] == "Prime");
}

TEST_CASE("testing 12 is not prime") {

    std::vector<std::string> input_lines = {
        "1",
        "12"
    };
    auto output_lines = runprog("../primes/primes", input_lines);

    CHECK(output_lines[0] == "Not Prime");
}


TEST_CASE("testing multiple lines of tests") {

    std::vector<std::string> input_lines = {
        "5",
        "1",
        "5",
        "2",
        "67",
        "957"
    };
    auto output_lines = runprog("../primes/primes", input_lines);

    CHECK(output_lines[0] == "Not Prime");
    CHECK(output_lines[1] == "Prime");
    CHECK(output_lines[2] == "Prime");
    CHECK(output_lines[3] == "Prime");
    CHECK(output_lines[4] == "Not Prime");
}
