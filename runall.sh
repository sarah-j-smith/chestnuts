#!/bin/bash
TOP=$PWD

for p in fibonacci fizzbuzz powerof graphspan primes bubblesort regex coins; do

    cd $p
    g++ -std=c++17 -stdlib=libc++  -stdlib=libc++ -I ./include -I ../include -Wall -O -o $p $p.cpp

    cd $TOP
    cd test
    g++ -std=c++17 -stdlib=libc++  -stdlib=libc++ -I ./include -I ../include -Wall -O -o $p $p.cpp

    ./$p
    cd $TOP

done