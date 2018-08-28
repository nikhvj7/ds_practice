#ifndef BST_HPP_
#define BST_HPP_


class BinarySearchTree{

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(int element);
	void remove(int element);
	bool isEmpty();
	void printTree();
	void searchElement(int data);
private:

	struct Node{
		int data;
		Node* leftChild;
		Node* rightChild;


	};

	void traverse(Node* temp);
	void search(Node* temp, int data);
	int getMin(Node* temp);
	int getMax(Node* temp);

	struct Node* deleteNode(Node* temp, int data);

	Node* root;

};

#endif