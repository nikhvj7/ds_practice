#include <iostream>

class ListADT{

public:
	ListADT();
	~ListADT();
	void insert(int element, int position);
	void remove(int position);
	int size();
	void printList();
private:
	
	int* _data;
	int _size;
	int _end;
};


