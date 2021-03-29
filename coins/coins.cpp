#include <functional>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "commandline.hpp"

// Uncomment for small sizes of change to see a table of 
// #define PRINT_TABLE 1

// Complete the ways function below.
int ways(int n, vector<int> coins) {

    const int table_size = n + 1;
    vector<long> change_table(table_size, 0l);
    change_table[0] = 1l;

#ifdef PRINT_TABLE
    printf("     ");
    for (int i = 0; i < change_table.size(); ++i) {
        printf("%5li  ", (long)i);
    }
    printf("\n");
#endif

    for (auto coin: coins) {
        for (int amount = coin; amount < table_size; ++amount) {
            change_table[amount] += change_table[amount - coin];
        }

#ifdef PRINT_TABLE
        printf("%5d", coin);
        for (int i = 0; i < change_table.size(); ++i) {
            printf("%5li  ", change_table[i]);
        }
        printf("\n");
#endif

    }
    return change_table[n];
}

int main()
{
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string coins_input;
    getline(cin, coins_input);

    vector<string> coin_string_values = split_string(coins_input);

    vector<int> coins(m);

    for (int i = 0; i < m; i++) {
        int coins_item = stoi(coin_string_values[i]);
        coins[i] = coins_item;
    }

    int res = ways(n, coins);

    cout << res << "\n";

    return 0;
}
