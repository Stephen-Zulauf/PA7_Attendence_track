#include "config.h"
#include "Data.h"
#include "List.h"
#include "FileLoader.h"
#include "Menu.h"


int main() {

	//create student list
	List<Node<Data>> studentList;

	//file loader
	FileLoader loader("classList.csv", &studentList);
	if (loader.loadFile()) {
		std::cout << "Loaded: classList.csv" << std::endl;
	}

	//run main menu
	std::vector<std::string> nOptions = {
		"Import Course List",
		"Load Course List",
		"Store Course List",
		"Mark Absences",
		"Edit Absences",
		"Generate Report",
		"Exit"
	};

	Menu mainMenu("Main menu", nOptions);
	mainMenu.print();

	std::string choice = "0";
	while (stoi(choice) != 7) {

		std::cin >> choice;

		switch (stoi(choice)) {
		case 1:
			//Import Course List

			//delete list if there
			studentList.deleteList();

			//load file 
			if (loader.loadFile()) {
				system("cls");
				mainMenu.print();
				std::cout << "Loaded: classList.csv" << std::endl;
			}
			else {
				system("cls");
				mainMenu.print();
				std::cout << "Failed to load: classList.csv" << std::endl;
			}

			break;
		case 2:
			//Load Course List
			system("cls");
			mainMenu.print();
			break;
		case 3:
			//Store Course List
			system("cls");
			mainMenu.print();
			break;
		case 4:
			//Mark Absences
			system("cls");
			mainMenu.print();
			break;
		case 5:
			//Edit Absences
			system("cls");
			mainMenu.print();
			break;
		case 6:
			//Generate Report
			system("cls");
			mainMenu.print();
			break;
		case 7:
			//Exit
			system("cls");
			std::cout << "Goodbye" << std::endl;
			break;
		default:
			std::cout << "Please enter a valid choice" << std::endl;
		}

	}


	return 0;
}