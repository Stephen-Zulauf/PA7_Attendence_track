#pragma once

#include "config.h"
#include "Node.h"

template<typename T>
class List {
private:
	std::vector<T*> mList;

public:

	//member functions

	//setters
	void push(T* nData);
	void pop();
	void deleteList();
	
	//getters
	T* peek();
	bool isEmpty();

};

template <typename T>
void List<T>::push(T* nData) {
	this->mList.push_back(nData);
}

template <typename T>
void List<T>::pop() {
	this->mList.pop_back();
}

template <typename T>
void List<T>::deleteList() {
	for (int i = 0; i < this->mList.size(); i++) {
		delete this->mList[i];
	}
	this->mList.clear();
}

template <typename T>
T* List<T>::peek() {
	return this->mList.back();
}

//returns true if list is empty
template <typename T>
bool List<T>::isEmpty() {
	return this->mList.empty();
}