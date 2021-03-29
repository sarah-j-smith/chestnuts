#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

TEST_CASE("testing binary runs") {

    std::vector<std::string> input_lines = {
        "20"
    };
    auto output_lines = runprog("../fibonacci/fibonacci", input_lines);

    CHECK(output_lines[0] == "{ 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 }");
}
