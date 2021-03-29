#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

// Your local library needs your help! Given the expected and actual return dates 
// for a library book, create a program that calculates the fine (if any).
// 
// Take in the following input:
//    - actual return date:   
//          dd mm yyyy
//    - due date:  
//          dd mm yyyy
//
// (No need to validate these - assumed to be valid dates)
//
// The fee structure is as follows:
//
// If the book is returned on or before the expected return date, 
// no fine will be charged (i.e.: fine = 0)
//
// If the book is returned after the expected return day but still 
// within the same calendar month and year as the expected return date, 
// (i.e.: fine = 15 x days_late)
//
// If the book is returned after the expected return month but still within
//  the same calendar year as the expected return date, the 
//  fine = 500 x months_late.
//
// If the book is returned after the calendar year in which it was expected, 
// there is a fixed fine of 10,000 

TEST_CASE("return is on time") {

    std::vector<std::string> input_lines = {
        "9 6 2015",
        "9 6 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "0");
}

TEST_CASE("return is before time - prev day") {

    std::vector<std::string> input_lines = {
        "29 5 2015",
        "9 6 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "0");
}

TEST_CASE("return is before time - prev month") {

    std::vector<std::string> input_lines = {
        "29 5 2015",
        "9 6 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "0");
}

TEST_CASE("return is on time - prev year") {

    std::vector<std::string> input_lines = {
        "29 12 2014",
        "5 1 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "0");
}

TEST_CASE("return is on 3 days late") {

    std::vector<std::string> input_lines = {
        "9 6 2015",
        "6 6 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "45");
}

TEST_CASE("return is 3 months late") {

    std::vector<std::string> input_lines = {
        "9 9 2015",
        "9 6 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "1500");
}

TEST_CASE("return is next calendar year") {

    std::vector<std::string> input_lines = {
        "9 6 2016",
        "9 9 2015"
    };
    auto output_lines = runprog("../logic/logic", input_lines);

    CHECK(output_lines[0] == "10000");
}
