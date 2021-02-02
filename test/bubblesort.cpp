#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.h"

TEST_CASE("testing with 3 numbers case") {

    std::vector<std::string> input_lines = {
        "3",
        "51 26 82"
    };
    auto output_lines = runprog("../bubblesort/bubblesort", input_lines);

    CHECK(output_lines[0] == "26 51 82");
}

TEST_CASE("testing with 3 identical numbers case") {

    std::vector<std::string> input_lines = {
        "3",
        "1000 1000 1000"
    };
    auto output_lines = runprog("../bubblesort/bubblesort", input_lines);

    CHECK(output_lines[0] == "1000 1000 1000");
}

TEST_CASE("testing the empty case") {

    std::vector<std::string> input_lines = {
        "0"
    };
    auto output_lines = runprog("../bubblesort/bubblesort", input_lines);

    CHECK(output_lines.size() == 0);
}

TEST_CASE("larger list with 22 values positive numbers") {

    std::vector<std::string> input_lines = {
        "22"
    };

    const uint32_t max_int = 2048;
    std::vector<int> numbers;
    {
        std::stringstream inputs;
        for (int r = 0; r < 22; ++r) {
            auto rand_num = arc4random_uniform(max_int);
            numbers.push_back(rand_num);
            inputs << rand_num << " ";
        }
        input_lines.push_back(inputs.str());
    }

    std::sort(numbers.begin(), numbers.end());
    std::string sorted_line;
    {
        std::stringstream expected;
        for (auto n: numbers) {
            expected << n << " ";
        }
        sorted_line = expected.str();
        trim(sorted_line);
    }

    auto output_lines = runprog("../bubblesort/bubblesort", input_lines);

    CHECK(output_lines[0] == sorted_line);
}

TEST_CASE("larger list with 22 values positive & negative numbers") {

    std::vector<std::string> input_lines = {
        "22"
    };

    const uint32_t max_val = 2048;
    std::vector<int> numbers;
    {
        std::stringstream inputs;
        for (int r = 0; r < 22; ++r) {
            int rand_num = arc4random_uniform(max_val) - (max_val/2);
            numbers.push_back(rand_num);
            inputs << rand_num << " ";
        }
        input_lines.push_back(inputs.str());
    }

    std::sort(numbers.begin(), numbers.end());
    std::string sorted_line;
    {
        std::stringstream expected;
        for (auto n: numbers) {
            expected << n << " ";
        }
        sorted_line = expected.str();
        trim(sorted_line);
    }

    auto output_lines = runprog("../bubblesort/bubblesort", input_lines);

    CHECK(output_lines[0] == sorted_line);
}
