#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

TEST_CASE("testing with 4 denominations and low change case") {

    std::vector<std::string> input_lines = {
        "10 4",
        "2 5 3 6"
    };
    auto output_lines = runprog("../coins/coins", input_lines);

    CHECK(output_lines[0] == "5");
}

TEST_CASE("testing with 5 denominations and more change amount") {

    std::vector<std::string> input_lines = {
        "67 5",
        "16 20 12 3 5"
    };
    auto output_lines = runprog("../coins/coins", input_lines);

    CHECK(output_lines[0] == "55");
}

TEST_CASE("name"
          * doctest::description("shouldn't take more than 500ms")
          * doctest::timeout(0.5)) {
    std::vector<std::string> input_lines = {
        "222 24",
        "3 25 34 38 26 42 16 10 15 50 39 44 36 29 22 43 20 27 9 30 47 13 40 33"
    };
    auto output_lines = runprog("../coins/coins", input_lines);

    CHECK(output_lines[0] == "5621927");
}