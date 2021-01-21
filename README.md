# Chestnuts

Some average to middling solutions to the chestnut questions that
sometimes get posed in tech interviews.

No attempt has been made to be clever, or to add unit tests or anything
like that.  This is basically as I would do if I were actually in an
interview.

## Update

The `graphspan` example at the end was a bit more complex so I added unit
tests and some example data for that.

## Pre-Requisites

You just need a [C++ compiler](https://webkit.org/build-tools/), and a
command line.

## Visual Studio Code

Config files for Visual Studio Code are included in case that's installed.
To use these, install the C/C++ extension.

## fibonacci 

Calculates the [Fibonacci sequence](https://codercareer.blogspot.com/2011/10/no-15-fibonacci-sequences.html).  Known issues: doesn't work with larger numbers.

Does not use recursion as this is inefficient and a [tabulated approach with a vector works nicely](https://youtu.be/oBt53YbR9Kk?t=11479).

To run:

    cd fibonacci
    g++ -o fibonacci fibonacci.cpp

    ./fibonacci


## fizzbuzz

Display the _FizzBuzz_ sequence. Described [on C2 wiki](http://wiki.c2.com/?FizzBuzzTest).

> Write a short program that prints each number from 1 to 50 on a new line. 
> For each multiple of 3, print "Fizz" instead of the number. 
> For each multiple of 5, print "Buzz" instead of the number. 
> For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.

To run:

    cd fizzbuzz
    g++ -o fizzbuzz fizzbuzz.cpp

    ./fizzbuzz

*Input*

The fizzbuzz series is hard-coded to 50, as per the question text. No user input is required.

## powerof

Find if a number is a power of another number. From a [post by American Dreamer](https://hardcoded.medium.com/coding-interview-question-for-sdet-role-daa0c8eb230f)

> Initally write a program to check if given number is power of three. What about other bases than 3?

    cd powerof
    g++ -O powerof.cpp -o powerof
    ./powerof

*Input*

to ask if 19683 is a power of 3, start the program, type `19683` and press `<ctrl>-D` (EOF). As per the spec,
the base of 3 is the default.  If `true` is the result, that means, yes it is a power of 3:

    ./powerof
    19683<EOF>
    true

to ask if 125 is a power of 5, start the program, type `125` and press `<enter>`, then type 5, then press `<enter>`:

    ./powerof
    25
    5
    true

*Tests*

    cd test
    g++ -std=c++17 -stdlib=libc++ -Wall -O powerof.cpp -o powerof
    ./powerof

## graphspan

Determine if a graph contains a specified path.

> Input shall be as follows:
> line 0: n
> Next n lines: A,B - where A and B are city names
> Last line S,D - source and dest to find path
> Print "true" or "false" if a path exists

Note that this is a reduced requirement from a more general shortest path
search which can be solved by A* or Djikstra's algorithm. This does not
require printing the path, or finding a shortest path - so it can exit early.

To run:

    cd graphspan
    g++ -std=c++17 -stdlib=libc++ -Wall -O graphspan.cpp -o graphspan

    ./graphspan < example.txt

To run tests:

    cd test
    g++ -std=c++17 -stdlib=libc++ -Wall -O graphspan.cpp -o graphspan
    ./graphspan

The tests use [doctest](https://github.com/onqtam/doctest) which is simply included here as a header file.

![screenshot](doc/passing-tests.png)

If the tests are passing the result should look as above.