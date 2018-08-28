#include "LinkedList.hpp"

LinkedList::LinkedList(){
	_head = nullptr;
}

LinkedList::~LinkedList(){
	Node* temp;
	while(_head != nullptr){
		temp = _head->next;
		delete _head;
		_head = temp;
	}


}

void LinkedList::insert(int element, int position){

	if(position > getSize()){
		std::cout << "Invalid position dumbfuck" << std::endl;
	}

	if(position == 0){
				
		Node* temp = _head;
		_head = new Node;
		_head->element = element;
		_head->next = temp;
		
		return;
	}

	//insert at beginning of linked list
	// if(position == 0){
	// 	if(position > 0){
	// 		std::cout << "Invalid position for empty list" << std::endl;
	// 		return;
	// 	}

	// 	_head = new Node;
	// 	_head->element = element;
	// 	_head->next = nullptr;
	// 	return;
	// }
	//insert at end of linked list

	// if(position == getSize()){
	// 	Node* temp = _head;

	// 	while(_head->next != nullptr){
	// 		_head = _head->next;
	// 	}

		
	// 	_head->next = new Node;
	// 	_head->next->element = element;
	// 	_head->next->next = nullptr;
	// 	_head = temp;
	// 	return;	
	// }

	Node* temp = _head;

	for(int i = 0; i < position-1; i++){
		temp = temp->next;
	}

	Node* temp2 = temp->next;
	temp->next = new Node;
	temp->next->element = element;
	temp->next->next = temp2;

}



//Alternate Insert

// if(position == 0){
// 	Node* temp = new Node;
// 	temp->element = element;
// 	temp->next = _head;
// 	_head = temp;
// }

void LinkedList::remove(int position){
	if(position > getSize() - 1){
		std::cout << "Invalid position" << std::endl;
		return;
	}

	if(position == 0){
		Node* temp = _head->next;
		delete _head;
		_head = temp;
		return;
	}

	Node* temp = _head;
	Node* temp2 = temp->next;
	for(int i = 0; i < position-1; i++){
		temp = temp->next;
		temp2 = temp2->next;
	}

	temp->next = temp2->next;
	delete temp2;
	
}

int LinkedList::getSize(){
	int count = 0;
	Node* temp = _head;
	while(temp != nullptr){
		count++;
		temp = temp->next;
	}
	return count;
}

void LinkedList::printList(){

	//Remember to create a different variable and not use head because you will lose the reference and cause bugs during insertion
	Node* temp = _head;
	while(temp != nullptr){
		std::cout << temp->element << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


//iterative solution done by ME
void LinkedList::reverseList(){

	Node* temp;
	Node* temp2 = _head;
	Node* temp3 = _head;
	

	if(temp2->next == nullptr){
		return;
	}

	while(temp2->next != nullptr){
		temp2 = temp2->next;
	}

	temp = temp2;

	while(temp2 != _head){
	
		while(temp3->next != temp2){
			temp3 = temp3->next;
		}

		temp2->next = temp3;
		temp2 = temp3;
		temp3 = _head;		
	}
	_head->next = nullptr;
	_head = temp;
	

}

//not parameterized
void LinkedList::printListRecursive(){
	static Node* temp = _head;

	if(_head != nullptr){
		std::cout << _head->element << " ";
		_head = _head->next;
		printListRecursive();

	}
	else{
		std::cout << std::endl;

		_head = temp;	
	}
	

}

//parameterized !!! you cannot call this in main. only within the class since _head is not accessible outisde the class. But this method is good to know
// void LinkedList::printListRecursivewithParam(Node* p){
// 	if(p == nullptr){
// 		std::cout << std::endl;
// 		return;
// 	}
// 	std::cout << p->element << " ";
// 	printListRecursivewithParam(p->next);
// }

void LinkedList::printListReverseRecursive(){
	static Node* temp = _head;

	if(_head != nullptr){
		_head = _head->next;
		printListReverseRecursive();
		std::cout << _head->element << " ";
	}
	if(temp == _head){
		std::cout << std::endl;
	}

}