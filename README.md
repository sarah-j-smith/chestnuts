# Chestnuts

Some average to middling solutions to the chestnut questions that
sometimes get posed in tech interviews.

No attempt has been made to be clever, or to add unit tests or anything
like that.  This is basically as I would do if I were actually in an
interview.

## fibonacci 

Calculates the [Fibonacci sequence](https://codercareer.blogspot.com/2011/10/no-15-fibonacci-sequences.html).  Known issues: doesn't work with larger numbers.

Does not use recursion as this is inefficient and a memo-ized vector works.

To run:

    g++ -o fibonacci -std=c++14 main.cpp

    ./fibonacci


## fizzbuzz

Display the _FizzBuzz_ sequence. Described [on C2 wiki](http://wiki.c2.com/?FizzBuzzTest).

To run:


    g++ -o fizzbuzz main.cpp

    ./fizzbuzz
