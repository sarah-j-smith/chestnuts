#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

TEST_CASE("testing base case with powers of 3") {

    std::vector<std::string> input_lines = {
        "21",
        "3"
    };
    auto output_lines = runprog("../powerof/powerof", input_lines);

    CHECK(output_lines[0] == "false");
}

TEST_CASE("testing larger number with powers of 3") {

    std::vector<std::string> input_lines = {
        "19683",
        "3"
    };
    auto output_lines = runprog("../powerof/powerof", input_lines);

    CHECK(output_lines[0] == "true");
}

TEST_CASE("testing for false in a number close above a true case") {

    std::vector<std::string> input_lines = {
        "19684",
        "3"
    };
    auto output_lines = runprog("../powerof/powerof", input_lines);

    CHECK(output_lines[0] == "false");
}

TEST_CASE("testing for false in a number close below a true case") {

    std::vector<std::string> input_lines = {
        "19682",
        "3"
    };
    auto output_lines = runprog("../powerof/powerof", input_lines);

    CHECK(output_lines[0] == "false");
}

TEST_CASE("testing for other base true case") {

    std::vector<std::string> input_lines = {
        "125",
        "5"
    };
    auto output_lines = runprog("../powerof/powerof", input_lines);

    CHECK(output_lines[0] == "true");
}


TEST_CASE("testing for other base false case") {

    std::vector<std::string> input_lines = {
        "512",
        "5"
    };
    auto output_lines = runprog("../powerof/powerof", input_lines);

    CHECK(output_lines[0] == "false");
}
