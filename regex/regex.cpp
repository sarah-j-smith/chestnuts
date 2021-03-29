#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <algorithm>

#include "commandline.hpp"

using namespace std;

#define GMAIL "gmail.com"

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> names;
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string command_line_input;
        getline(cin, command_line_input);

        vector<string> input_values = split_string(command_line_input);

        string firstName = input_values[0];

        string emailID = input_values[1];

        regex email_regex("([^@]+)@([^@]+)");
        smatch domain_matches;
        if (regex_match(emailID, domain_matches, email_regex)) {
            if (domain_matches.size() > 2) {
                if (domain_matches[2] == GMAIL) {
                    names.push_back(domain_matches[1]);
                }
            }
        }
    }
    sort(names.begin(), names.end());
    for (const auto &n: names) {
        cout << n << endl;
    }

    return 0;
}
