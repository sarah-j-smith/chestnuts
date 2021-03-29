#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int fine = 0;
    int day, month, year;
    cin >> day >> month >> year;
    int due_day, due_month, due_year;
    cin >> due_day >> due_month >> due_year;
    
    if (due_year == year) {
        if (due_month == month) {
            if (due_day < day) {
                fine = 15 * (day - due_day);
            }
            // else due_day >= month -> fine == 0
        } else if (due_month < month) {
            fine = 500 * (month - due_month);
        } 
        // else due_month > month -> fine == 0
    } else if (due_year < year) {
        fine = 10000;
    }
    // else due_year > year -> fine == 0
    cout << fine << endl;
    return 0;
}
