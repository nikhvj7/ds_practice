#include "LinkedList.hpp"

int main(){

	LinkedList list;
	list.insert(3,0);
	list.insert(5, 0);
	list.insert(6,0);
	list.insert(7,1);
	list.insert(10,2);
	list.insert(5,1);
	list.insert(6,0);
	list.insert(48, 5);

	list.remove(3);

	list.printList();

	list.reverseList();

	list.printList();

	list.printListRecursive();

	list.printListReverseRecursive();
	
	std::cout << "Size of List: " << list.getSize() << std::endl;




	return 0;
}