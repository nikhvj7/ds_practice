
template <typename T>
Stack<T>::Stack(){
	top = nullptr;
}

template <typename T>
Stack<T>::~Stack(){

	while(top != nullptr){
		pop();
	}
}

template <typename T>
void Stack<T>::push(T element){

	if(top == nullptr){
		top = new Node<T>;
		top->data = element;
		top->next = nullptr;
		return;
	}

	Node<T>* temp = new Node<T>;
	temp->data = element;
	temp->next = top;
	top = temp;

}

template <typename T>
void Stack<T>::pop(){

	if(top == nullptr){
		return;
	}

	Node<T>* temp = top;
	top = temp->next;
	delete temp;
	
}

template <typename T>
T Stack<T>::getTop(){
	if(top != nullptr){
		return top->data;
	}
	return 'c';
	
}

template <typename T>
bool Stack<T>::isEmpty(){
	return(top == nullptr);
}

template <typename T>
void Stack<T>::displayStack(){
	Node<T>* temp = top;
	while(temp != nullptr){
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}