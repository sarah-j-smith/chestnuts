#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(vector<int> &elements) {
    // bubble sort from low to high
    int last = elements.size();
    while(last > 0) {
        bool was_swapped = false;
        for (int ix = 1; ix != last; ++ix) {
            if (elements[ix - 1] > elements[ix]) {
                swap(elements[ix - 1], elements[ix]);
                was_swapped = true;
            }
        }
        if (!was_swapped) { break; }
        // Uncomment to see the successive stages of the sort
        // for (auto el: elements) {
        //     cout << el << " ";
        // }
        // cout << endl;
        --last;
    }
}; 

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }

    // Uncomment to get debug output of the inputted data
    // cout << "Unsorted:" << endl;
    // for(auto el: a) {
    //     cout << el << " ";
    // }
    // cout << endl;

    bubble_sort(a);

    // cout << "Sorted:" << endl;
    for(auto el: a) {
        cout << el << " ";
    }
    
    cout << endl;
    
    return 0;
}