#include "BST.hpp"
#include <iostream>

BinarySearchTree::BinarySearchTree(){
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){

}

void BinarySearchTree::insert(int element){

	if(root == nullptr){
		root = new Node;
		root->data = element;
		root->leftChild = nullptr;
		root->rightChild = nullptr;
		return;
	}

	Node* temp = root;
	Node* temp2;

	while(temp != nullptr){
		if(element > temp->data){
			temp2 = temp;
			temp = temp->rightChild;
		}
		else{
			temp2 = temp;
			temp = temp->leftChild;
		}
	}
	if(element > temp2->data){
		temp2->rightChild = new Node;
		temp2->rightChild->data = element;
		temp2->rightChild->rightChild = nullptr;
		temp2->rightChild->leftChild = nullptr;
	}
	else{
		temp2->leftChild = new Node;
		temp2->leftChild->data = element;
		temp2->leftChild->rightChild = nullptr;
		temp2->leftChild->leftChild = nullptr;	
	}
}

void BinarySearchTree::remove(int element){

	root = deleteNode(root, element);
}

bool BinarySearchTree::isEmpty(){
	return(root == nullptr);
}

void BinarySearchTree::printTree(){
	
	Node* temp = root;

	traverse(root);
}


void BinarySearchTree::searchElement(int data){
	search(root, data);
}



/* PRIVATE MEMBERS FUNCTIONS */


void BinarySearchTree::traverse(Node* temp){ 
	//static int calls = 0;
	if(temp == nullptr){
		
	}
	else{
		
		std::cout << temp->data << std::endl;

		traverse(temp->leftChild);

		traverse(temp->rightChild);
		
	}
	
}

void BinarySearchTree::search(Node* temp, int data){
	if(temp == nullptr){
		std::cout << "Item not found" << std::endl;
		return;
	}
	else{
		if(data > temp->data){
			search(temp->rightChild, data);
		}
		else if(data < temp->data){
			search(temp->leftChild, data);
		}
		else{
			std::cout << "Element found!" << std::endl;
		}
	}
}

int BinarySearchTree::getMin(Node* temp){
	if(temp->leftChild == nullptr){
		return temp->data;
	}
	else{
		int min = getMin(temp->leftChild);
		return min;
	}
	
}

int BinarySearchTree::getMax(Node* temp){
	if(temp->rightChild == nullptr){
		return temp->data;
	}
	else{
		int max = getMax(temp->rightChild);
		return max;
	}
	
}
//NOT WORKING
BinarySearchTree::Node* BinarySearchTree::deleteNode(Node* temp, int data){
	if(temp == nullptr){
		return temp;
	}
	else if(data > temp->data) temp->rightChild = deleteNode(temp->rightChild, data);
	else if(data < temp->data) temp->leftChild = deleteNode(temp->leftChild, data);
	else{
		if(temp->leftChild == nullptr && temp->rightChild == nullptr){
			delete temp;
			temp = nullptr;
			
		}
		else if(temp->leftChild == nullptr){
			Node* temp2 = temp;
			temp = temp->rightChild;
			delete temp2;
			
		}
		else if(temp->rightChild == nullptr){
			Node* temp2 = temp;
			temp = temp->leftChild;
			delete temp2;
			
		}
		else{
			temp->data = getMin(temp->rightChild);
			temp->rightChild = deleteNode(temp->rightChild, temp->data);
		}
	}
	return temp;
}