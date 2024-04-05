
#include "Stack.h"

void Stack::push(std::string nDate) {
	this->sMain.push_back(nDate);
}
std::string Stack::pop() {
	std::string temp;
	temp = this->sMain.back();

	this->sMain.pop_back();
	return temp;
}
std::string Stack::peek() {
	std::string temp;
	temp = this->sMain.back();

	return temp;
}
void Stack::print() {
	std::cout << "[";
	for (int i = 0; i < this->sMain.size(); i++) {
		std::cout << this->sMain[i];
		std::cout << ",";
	}
	std::cout << "]";
}
//returns true if list is empty
bool Stack::isEmpty() {

	return this->sMain.empty();

}