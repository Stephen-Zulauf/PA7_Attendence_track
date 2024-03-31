#include "Menu.h"

//run menu
void Menu::print() {
	
	std::cout << this->title << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	for (int i = 0; i < this->options.size(); i++) {
		std::cout << i+1 << ") " << options[i] << std::endl;
	}
	std::cout << "-----------------" << std::endl;
}