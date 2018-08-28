g++ -std=c++11 -c LinkedList.cpp -o LinkedList.o
g++ -std=c++11 -c main.cpp -o main.o
g++ -std=c++11 LinkedList.o main.o -o main
