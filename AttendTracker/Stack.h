#pragma once

#include "config.h"

class Stack {
private:
	std::vector<std::string> sMain;

public:
	Stack() {

	}
	Stack(Stack& copy) {
		for (int i = 0; i < copy.sMain.size(); i++) {
			this->sMain.push_back(copy.sMain[i]);
		}
	}
	~Stack() {
		//std::cout << "stack destructor called" << std::endl;

	}

	void push(std::string nData);
	std::string pop();
	std::string peek();
	void print();
	//returns true if list is empty
	bool isEmpty();
};