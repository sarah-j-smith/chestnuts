#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void displayVector(vector<long long> vec)
{
    cout << "{ ";
    string sep = "";
    for (auto iv : vec)
    {
        cout << sep << iv;
        sep = ", ";
    }
    cout << " }" << endl;
}

vector<long long> fibonacci(int sequenceLength)
{
    vector<long long> result;
    
    if (sequenceLength == 0)
    {
        return result;
    }
    result.push_back(1ll);
    if (sequenceLength == 1)
    {
        return result;
    }
    result.push_back(1ll);
    if (sequenceLength == 2)
    {
        return result;
    }

    for (int i = 2; i < sequenceLength; ++i)
    {
        result.push_back( result[i - 2] + result[i - 1] );
    }

    return result;
}

int main(int argc, char *argv[])
{
    unsigned int inputVal = 0;

    inputVal = 0;
    cin >> inputVal;
    auto result = fibonacci(inputVal);
    displayVector(result);

    return 0;
}
