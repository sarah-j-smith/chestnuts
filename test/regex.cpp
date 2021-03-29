#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

TEST_CASE("testing 6 basic email addresses") {

    std::vector<std::string> input_lines = {
        "6",
        "riya riya@gmail.com",
        "julia julia@julia.me",
        "julia sjulia@gmail.com",
        "julia julia@gmail.com",
        "samantha samantha@gmail.com",
        "tanya tanya@gmail.com"
    };
    auto output_lines = runprog("../regex/regex", input_lines);

    CHECK(output_lines[0] == "julia");
    CHECK(output_lines[1] == "riya");
    CHECK(output_lines[2] == "samantha");
    CHECK(output_lines[3] == "sjulia");
    CHECK(output_lines[4] == "tanya");
}
