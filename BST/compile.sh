#!/bin/bash

g++ -std=c++11 -c BST.cpp -o BST.o
g++ -std=c++11 -c main.cpp -o main.o
g++ -std=c++11 BST.o main.o -o main
