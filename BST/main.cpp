#include "BST.hpp"
#include <iostream>

int main(){

	BinarySearchTree bst;

	if(bst.isEmpty()){
		std::cout << "tree is empty" << std::endl;
	}

	bst.insert(5);
	bst.insert(3);
	bst.insert(6);
	bst.insert(9);
	bst.insert(-3);
	bst.insert(4);

	bst.printTree();

	bst.remove(5);
	std::cout << std::endl; 
	bst.printTree();

	return 0;
}