
#include <stdio.h>

#include <vector>
#include <string>
#include <iostream>

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
 * Returns the sub-strings within the given input_values seperated by a linefeed.
 */
std::vector<std::string> componentsSeperatedByLinefeed(std::string input_values)
{
    auto components = std::vector<std::string>();
    std::stringstream input_stream(input_values);
    std::string buf;
    while (std::getline(input_stream, buf))
    {
        trim(buf);
        components.push_back(buf);
    }
    return components;
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

    pclose(handle);

    results = componentsSeperatedByLinefeed(result_str);

    return results;
}
