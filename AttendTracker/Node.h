#pragma once

#include "config.h"

template <typename T>
class Node {
private:
	T* data = nullptr;
	Node<T>* next = nullptr;

public:

	Node(T* nData, Node<T>* nNext ) {
		this->data = nData;
		this->next = nNext;
	}
	Node(Node& copy) {
		//TODO
	}
	~Node() {
		if (data) {
			delete data;
		}
		//std::cout << "Node destructer called" << std::endl;
	}

	//member defs

	//setters
	void setData(T* nData);
	void setNext(Node<T>* nNode);

	//getters
	T* getData();
	Node<T>* getNext();
};

template <typename T>
void Node<T>::setData(T* nData) {
	this->Data = nData;
}

template <typename T>
void Node<T>::setNext(Node<T>* nNode) {
	this->next = nNode;
}

template <typename T>
T* Node<T>::getData(){
	return this->data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
	return this->next;
}