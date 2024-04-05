#pragma once

#include "config.h"
#include "Node.h"

template<typename T>
class List {
private:
	std::vector<T*> mList;
	std::string date;


public:
	List() {
		time_t t = time(0); // get time now
		struct tm* now = localtime(&t);
		date += std::to_string((now->tm_mon + 1));
		date += "/";
		date += std::to_string(now->tm_mday);
		std::cout << "current date:" << this->date << std::endl;
	}
	List(const List& copy) {
		this->mList = copy.mList;
		this->date = copy.date;
	}
	~List() {
		for (int i = 0; i < mList.size(); i++) {
			delete this->mList[i];
		}
		this->date.erase();

	}

	//setters
	void push(T* nData);
	void pop();
	void deleteList();
	
	//getters
	T* peek();
	int getSize();
	bool isEmpty();
	std::string getDate();


};

template <typename T>
void List<T>::push(T* nData) {
	this->mList.push_back(nData);
}

template <typename T>
void List<T>::pop() {
	delete this->mList.back();
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

template <typename T>
int List<T>::getSize() {
	return this->mList.size();
}

//returns true if list is empty
template <typename T>
bool List<T>::isEmpty() {
	return this->mList.empty();
}

template <typename T>
std::string List<T>::getDate() {
	return this->date;
}
