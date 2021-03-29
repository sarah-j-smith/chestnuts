#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

TEST_CASE("testing binary runs")
{

    std::vector<std::string> input_lines { };
    auto output_lines = runprog("../fizzbuzz/fizzbuzz", input_lines);

    CHECK(output_lines[0] == "1");
    CHECK(output_lines[1] == "2");
    CHECK(output_lines[2] == "fizz");
    CHECK(output_lines[3] == "4");
    CHECK(output_lines[4] == "buzz");
    CHECK(output_lines[5] == "fizz");
    CHECK(output_lines[6] == "7");
    CHECK(output_lines[7] == "8");
    CHECK(output_lines[8] == "fizz");
    CHECK(output_lines[9] == "buzz");
    CHECK(output_lines[10] == "11");
    CHECK(output_lines[11] == "fizz");
    CHECK(output_lines[12] == "13");
    CHECK(output_lines[13] == "14");
    CHECK(output_lines[14] == "fizzbuzz");
    CHECK(output_lines[15] == "16");
    CHECK(output_lines[16] == "17");
    CHECK(output_lines[17] == "fizz");
    CHECK(output_lines[18] == "19");
    CHECK(output_lines[19] == "buzz");
    CHECK(output_lines[20] == "fizz");
    CHECK(output_lines[21] == "22");
    CHECK(output_lines[22] == "23");
    CHECK(output_lines[23] == "fizz");
    CHECK(output_lines[24] == "buzz");
    CHECK(output_lines[25] == "26");
    CHECK(output_lines[26] == "fizz");
    CHECK(output_lines[27] == "28");
    CHECK(output_lines[28] == "29");
    CHECK(output_lines[29] == "fizzbuzz");
    CHECK(output_lines[30] == "31");
    CHECK(output_lines[31] == "32");
    CHECK(output_lines[32] == "fizz");
    CHECK(output_lines[33] == "34");
    CHECK(output_lines[34] == "buzz");
    CHECK(output_lines[35] == "fizz");
    CHECK(output_lines[36] == "37");
    CHECK(output_lines[37] == "38");
    CHECK(output_lines[38] == "fizz");
    CHECK(output_lines[39] == "buzz");
    CHECK(output_lines[40] == "41");
    CHECK(output_lines[41] == "fizz");
    CHECK(output_lines[42] == "43");
    CHECK(output_lines[43] == "44");
    CHECK(output_lines[44] == "fizzbuzz");
    CHECK(output_lines[45] == "46");
    CHECK(output_lines[46] == "47");
    CHECK(output_lines[47] == "fizz");
    CHECK(output_lines[48] == "49");
    CHECK(output_lines[49] == "buzz");
}