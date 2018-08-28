#include "Stack.hpp"

bool CheckBalancedParanthesis(std::string str);
bool checkMatchingBrace(char OpeningBrace, char ClosingBrace);

int main(){
	

	std::string str;

	std::cout << "Enter string:" << std::endl;

	std::cin >> str;

	if(CheckBalancedParanthesis(str)){
		std::cout << "string has balanced parantheses" << std::endl;
	}
	else{
		std::cout << "string does not have balanced parantheses" << std::endl;	
	}

	return 0;
}


bool CheckBalancedParanthesis(std::string str){
	Stack<char> my_stack;

	for(int i = 0; i < str.length(); i++){
		if(str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == '<'){
			my_stack.push(str[i]);
		}
		else if(str[i] == ']' || str[i] == '}' || str[i] == ')' || str[i] == '>'){
			if(checkMatchingBrace(my_stack.getTop(), str[i])){
				my_stack.pop();
			}
			else{
				my_stack.push(str[i]);
			}
		}
		
	}

	return(my_stack.isEmpty());
}


bool checkMatchingBrace(char OpeningBrace, char ClosingBrace){

	if(OpeningBrace == '['){
		if(ClosingBrace == ']'){
			return true;
		}
		else{
			return false;
		}
	}

	if(OpeningBrace == '{'){
		if(ClosingBrace == '}'){
			return true;
		}
		else{
			return false;
		}
	}

	if(OpeningBrace == '('){
		if(ClosingBrace == ')'){
			return true;
		}
		else{
			return false;
		}
	}

	if(OpeningBrace == '<'){
		if(ClosingBrace == '>'){
			return true;
		}
		else{
			return false;
		}
	}
	return false;

}