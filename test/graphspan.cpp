#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stdio.h>

#include <vector>
#include <string>


// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

/**
 * Start the given program, send all of the lines in the given test_input to that
 * program, and then collect all its output. The program must send EOF or else
 * this function will block forever.
 */
std::vector<std::string> runprog(std::string prog, std::vector<std::string> test_input) {

    std::vector<std::string> results;

    FILE *handle = popen(prog.c_str(), "r+");

    if (handle == NULL) {
        std::cerr << "Could not launch graphspan binary to test" << std::endl;
        return results;
    }

    for (auto &&test_input_line : test_input)
    {
        auto ip = test_input_line + "\n";
        fwrite(ip.c_str(), 1, ip.size(), handle);
    }

    std::string result_str = "";
    char buf[64] = { '\0' };
    while ( fgets(buf, sizeof(buf) - 1, handle )) {
        result_str.append(buf);
    }
    trim(result_str);
    if (result_str.size() > 0) {
        results.push_back( result_str );
    }

    pclose(handle);

    return results;
}

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