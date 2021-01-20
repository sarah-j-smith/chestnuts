#include <iostream>
#include <vector>
#include <algorithm>

void displayVector(std::vector<int> vec)
{
    std::cout << "--- fib seq: " << vec.size() << "---" << std::endl;
    for (int iv : vec)
    {
        std::cout << "   " << iv << std::endl;
    }
    std::cout << "--- fib seq: " << vec.size() << "---" << std::endl;
}

std::vector<int> fibonacci(int sequenceLength)
{
    std::vector<int> result;
    
    if (sequenceLength == 0)
    {
        return result;
    }
    result.push_back(1);
    if (sequenceLength == 1)
    {
        return result;
    }
    result.push_back(1);
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

    while (true) {
        std::cout << "Fibonacci sequence length? (or ctrl-c to exit):" << std::endl;
        std::cout << "> ";
        std::cin >> inputVal;
        auto result = fibonacci(inputVal);
        displayVector(result);
    }

    return 0;
}
