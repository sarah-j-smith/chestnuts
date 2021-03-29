#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "commandline.hpp"

TEST_CASE("testing the graphspan 3 routes success case") {

    std::vector<std::string> input_lines = {
        "3",
        "London,Dubai",
        "Stuttgart,Changi",
        "Dubai,Jakarta",
        "Jakarta,London"
    };
    auto output_lines = runprog("../graphspan/graphspan", input_lines);

    CHECK(output_lines[0] == "true");
}

TEST_CASE("testing the graphspan 3 routes false case") {

    std::vector<std::string> input_lines = {
        "3",
        "London,Stuttgart",
        "Stuttgart,Changi",
        "Dubai,Jakarta",
        "Jakarta,London"
    };
    auto output_lines = runprog("../graphspan/graphspan", input_lines);

    CHECK(output_lines[0] == "false");
}

TEST_CASE("larger graph with 22 routes true case") {

    // this data set has one large island of 15 interconnected cities
    // and two other isolated islands of doha-toky-moscow and new york,
    // los angeles, toronto and houston. singapore to munich is a 9-hop
    // journey
    std::vector<std::string> input_lines = {
        "22",
        "Dubai,Bangkok",
        "London,Hong Kong",
        "Amsterdam,Seoul",
        "Paris,Singapore",
        "Frankfurt,Istanbul",
        "Taipei,Kuala Lumpur",
        "London,Madrid",
        "Barcelona,Munich",
        "Tokyo,Doha",
        "New York,Toronto",
        "Los Angeles,Houston",
        "Dubai,London",
        "Hong Kong,Amsterdam",
        "Seoul,Munich",
        "Singapore,Frankfurt",
        "Bangkok,Istanbul",
        "Taipei,London",
        "Amsterdam,Madrid",
        "Barcelona,Amsterdam",
        "Tokyo,Moscow",
        "New York,Toronto",
        "Los Angeles,Toronto",
        "Singapore,Dubai",
        "Singapore,Munich"
    };

    auto output_lines = runprog("../graphspan/graphspan", input_lines);

    CHECK(output_lines[0] == "true");
}

TEST_CASE("larger graph with 22 routes false case") {

    // this data set has one large island of 15 interconnected cities
    // and two other isolated islands of doha-toky-moscow and new york,
    // los angeles, toronto and houston. singapore to munich is a 9-hop
    // journey
    std::vector<std::string> input_lines = {
        "22",
        "Dubai,Bangkok",
        "London,Hong Kong",
        "Amsterdam,Seoul",
        "Paris,Singapore",
        "Frankfurt,Istanbul",
        "Taipei,Kuala Lumpur",
        "London,Madrid",
        "Barcelona,Munich",
        "Tokyo,Doha",
        "New York,Toronto",
        "Los Angeles,Houston",
        "Dubai,London",
        "Hong Kong,Amsterdam",
        "Seoul,Munich",
        "Singapore,Frankfurt",
        "Bangkok,Istanbul",
        "Taipei,London",
        "Amsterdam,Madrid",
        "Barcelona,Amsterdam",
        "Tokyo,Moscow",
        "Los Angeles,Toronto",
        "Singapore,Dubai",
        "Singapore,Houston"
    };

    auto output_lines = runprog("../graphspan/graphspan", input_lines);

    CHECK(output_lines[0] == "false");
}