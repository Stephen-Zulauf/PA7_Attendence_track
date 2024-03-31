#pragma once

#include "config.h"

class Menu {
private:
	std::string title;

	std::vector<std::string> options;

public:
	//init
	Menu(std::string nTitle, std::vector<std::string>& nOptions) {
		this->title = nTitle;
		for (int i = 0; i < nOptions.size(); i++) {
			options.push_back(nOptions[i]);
		}
	}
	//copy
	Menu(Menu& copy) {
		this->title = copy.title;
		for (int i = 0; i < copy.options.size(); i++) {
			options.push_back(copy.options[i]);
		}
	}
	//destructor
	~Menu() {
		
	}

	//run menu
	void print();
};