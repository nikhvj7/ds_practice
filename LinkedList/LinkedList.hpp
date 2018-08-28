#include <iostream>

class LinkedList{

public:
	LinkedList();
	~LinkedList();
	void insert(int element, int position);
	void remove(int position);
	int getSize();
	void printList();
	void printListRecursive();
	//void printListRecursivewithParam(Node* p);

	void printListReverseRecursive();

	void reverseList();

private:
	struct Node{
		int element;
		Node* next;
	};

	Node* _head;
};

