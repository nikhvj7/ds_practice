#include "ListADT.hpp"

ListADT::ListADT(){
	_size = 5;
	_data = new int[_size];
	_end = -1;
}

ListADT::~ListADT(){
	delete _data;
	_data = nullptr;
}

void ListADT::insert(int element, int position){

	if(position > _end+1){
		std::cout << "invalid position" << std::endl;
		return;
	}

	//growing the array
	if(_end+1 == _size){

		int* newdata = new int[_size*2];
		for(int i = 0; i <=_end; i++){
			newdata[i] = _data[i];
		}
		delete _data;
		_data = newdata;
		_size = _size*2;
	}

	if(position == _end+1){
		_data[position] = element;
		_end++;
		return;
	}

	for(int i = _end; i >=position; i--){
		_data[i+1] = _data[i];
	}

	_data[position] = element;
	_end++;



}

void ListADT::remove(int position){
	if(position > _end || position < 0){
		std::cout << "boi you are one fucked up individual" << std::endl;
		return;

	}

	if(position == _end){
		_end--;
		return;
	}

	for(int i = position; i < _end; i++){
		_data[i] = _data[i+1];
	}
	_end--;

}

int ListADT::size(){

	return _end+1;
}

void ListADT::printList(){
	if(_end != -1){
		for(int i = 0; i <= _end; i++){
			std::cout << _data[i] <<  " ";
		}
		std::cout << std::endl;
	}
	
}
