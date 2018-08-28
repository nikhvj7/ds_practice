#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>

template <typename T>
class Stack{
public:

	Stack();
	~Stack();
	void push(T element);
	void pop();
	T getTop();
	bool isEmpty();
	void displayStack();

private:

	template <typename U>
	struct Node{
		U data;
		Node<U>* next;
	};

	Node<T>* top;

};

#include "Stack.tpp"

#endif