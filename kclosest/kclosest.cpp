#include <queue>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto point_compare = [](vector<int> a, vector<int> b) {
            // a is less than b if a is closer to the origin than b
            auto distAsquared = (a[0] * a[0] + a[1] * a[1]);
            auto distBsquared = (b[0] * b[0] + b[1] * b[1]);
            return distAsquared < distBsquared;
        };
        // Include the underlying container to help with class template
        // argument deduction
        vector<vector<int>> pq_store;

        // max heap priority queue with largest element at the top
        // largest here will mean the farthest from [0, 0]
        // under the hood C++ STL uses a heap for this with pq_store
        // as the array. pop() and push() maintain the heap order
        priority_queue pq{point_compare, pq_store};

        for (auto it = points.cbegin(); it != points.cend(); ++it)
        {
            // push into the heap, and (via priority queue implementation)
            // sort so largest is on the top.
            pq.push(*it);
            if (pq.size() > k)
            {
                // this push made it larger than k so remove
                // the top (largest) element
                pq.pop();
            }
        }
        deque<vector<int>> result;
        while (pq.size() > 0)
        {
            result.push_front(pq.top());
            pq.pop();
        }
        vector<vector<int>> output_result(result.begin(), result.end());
        return output_result;
    }
};

int main(int argc, char *argv[]) {
    cout << "Run the tests in /test directory" << endl;
    return 0;
}