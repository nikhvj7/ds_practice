#include <iostream>
#include "ListADT.hpp"

using namespace std;

int main(){

	ListADT list;
	list.insert(3,0);
	list.insert(5,0);
	list.insert(4,2);
	list.remove(1);
	std::cout << "Size of List: " << list.size() << std::endl;

	list.printList();
	return 0;
}