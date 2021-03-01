#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print_primality(int p, map<int, bool> memo) {
    bool is_prime = false;
    auto m = memo.find(p);
    if (m == memo.end()) {
        if (p % 2 == 0) {
            // is not prime - even number
        } else {
            int f = 3;
            int max_f = sqrt(p);
            for ( ; f <= max_f; f += 2) {
                if (p % f == 0) {
                    break;
                } 
            }
            if (f > max_f) {
                is_prime = true;
            }
        }
        memo[p] = is_prime;
    } else {
        is_prime = m->second;
    }
    cout << (is_prime ? "Prime" : "Not Prime") << endl;
}

int main() {
    int case_count = 0;
    int prime_test = 0;
    map<int, bool> memo {
        { 1, false },
        { 2, true },
        { 3, true }
    };
    cin >> case_count;
    for (int i = 0; i < case_count; ++i) {
        cin >> prime_test;
        print_primality(prime_test, memo);
    }
    return 0;
}
