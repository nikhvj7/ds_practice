#!/bin/bash

g++ -std=c++11 -c ListADT.cpp -o ListADT.o
g++ -std=c++11 -c main.cpp -o main.o
g++ -std=c++11 ListADT.o main.o -o main
