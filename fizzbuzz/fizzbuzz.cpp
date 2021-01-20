#include <iostream>

int main(int argc, char *argv[])
{
    int max = 50;

    for (int i = 1; i <= max; ++i)
    {
        bool codeWordPrinted = false;
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            codeWordPrinted = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "buzz";
            codeWordPrinted = true;
        }
        if ( !codeWordPrinted )
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}
