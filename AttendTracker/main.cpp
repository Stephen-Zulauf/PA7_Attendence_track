#include "config.h"
#include "Data.h"
#include "List.h"
#include "FileLoaderV2.h"
#include "FileWriter.h"
#include "Menu.h"

int main() {

	//create student list
	List<Node<Data>> studentList;

	//file loader
	FileLoader loader(&studentList);
	if (loader.loadFile("master.csv")) {
		std::cout << "Loaded: master.csv" << std::endl;
	}

	//file writer
	FileWriter writer(&studentList);

	//run main menu
	std::vector<std::string> nOptions = {
		"Import Course List",
		"Load Course List",
		"Store Course List",
		"Mark Absences",
		"Generate Report",
		"Exit"
	};

	Menu mainMenu("Main menu", nOptions);
	mainMenu.print();

	std::string choice = "0";
	std::string buffer = " ";

	Node<Data>* temp = nullptr;
	
	while (stoi(choice) != 7) {
		buffer = " ";
		std::cin >> choice;

		switch (stoi(choice)) {
		case 1:
			//Import Course List

			//prompt to overwrite master
			do {
				system("cls");
				mainMenu.print();
				std::cout << "This will overwrite the master list. Are you sure?" << std::endl;
				std::cout << "yes/no" << std::endl;
				std::cin >> buffer;

			} while (!std::cin.fail() && buffer != "yes" && buffer != "no");

			if (buffer == "yes") {
				//delete list if there
				studentList.deleteList();

				//load file 
				if (loader.loadFile("classList.csv")) {
					system("cls");
					mainMenu.print();
					std::cout << "Loaded: classList.csv" << std::endl;

					//overwrite master
					writer.writeFile("master.csv");

					//reload master
					loader.loadFile("master.csv");
				}
				else {
					system("cls");
					mainMenu.print();
					std::cout << "Failed to load: classList.csv" << std::endl;
				}

			}
			else {
				system("cls");
				mainMenu.print();
				break;
			}

			
			break;
		case 2:
			//Load Course List

			//prompt to overwright changes
			do {
				system("cls");
				mainMenu.print();
				std::cout << "You will lose any unsaved changes to master list. Are you sure?" << std::endl;
				std::cout << "yes/no" << std::endl;
				std::cin >> buffer;

			} while (!std::cin.fail() && buffer != "yes" && buffer != "no");
			
			if (buffer == "yes") {
				//delete list
				studentList.deleteList();

				//load master to list 
				if (loader.loadFile("master.csv")) {
					system("cls");
					mainMenu.print();
					std::cout << "Loaded: master.csv" << std::endl;
					if (studentList.getSize() == 0) {
						std::cout << "Master Course list is empty..." << std::endl;
						std::cout << "have you imported a courselist file?" << std::endl;
					}
					else {
						std::cout << studentList.getSize() << " students in list" << std::endl;
					}
				}
				else {
					system("cls");
					mainMenu.print();
					std::cout << "Failed to load: master.csv" << std::endl;
				}

			}
			else {
				system("cls");
				mainMenu.print();
			}
			
			break;
		case 3:
			//Store Course List
			
			//prompt to overwright changes
			do {
				system("cls");
				mainMenu.print();
				std::cout << "Save changes to master list?" << std::endl;
				std::cout << "yes/no" << std::endl;
				std::cin >> buffer;

			} while (!std::cin.fail() && buffer != "yes" && buffer != "no");

			if (buffer == "yes") {

				//write list to master csv
				writer.writeFile("master.csv");

				//re-load master to list 
				if (loader.loadFile("master.csv")) {
					system("cls");
					mainMenu.print();
					std::cout << "loaded: master.csv" << std::endl;
					if (studentList.getSize() == 0) {
						std::cout << "Master Course list is empty..." << std::endl;
						std::cout << "have you imported a courselist file?" << std::endl;
					}
					else {
						std::cout << studentList.getSize() << " students in list" << std::endl;
					}
				}
				else {
					system("cls");
					mainMenu.print();
					std::cout << "Failed to load: master.csv" << std::endl;
				}

			}
			else {
				system("cls");
				mainMenu.print();
			}

			break;
		case 4:
			//Mark Absences
			
			if (!studentList.isEmpty()) {
				temp = studentList.peek();
				while (temp) {

					do {
						system("cls");
						std::cout << "-------------------------" << std::endl;
						temp->getData()->print();
						std::cout << std::endl;
						std::cout << "-------------------------" << std::endl;
						std::cout << "Present?" << std::endl;
						std::cout << "yes/no" << std::endl;
						std::cin >> buffer;

					} while (!std::cin.fail() && buffer != "yes" && buffer != "no");

					if (buffer == "no") {
						temp->getData()->newAbs(studentList.getDate());
					}

					temp = temp->getNext();
				}
				system("cls");
				mainMenu.print();

			}
			else {
				system("cls");
				mainMenu.print();
				std::cout << "no course list loaded...." << std::endl;
			}
			
			break;

		case 5:
			//Generate Report
			if (!studentList.isEmpty()) {
				do {
					system("cls");
					mainMenu.print();
					std::cout << "Which Report would you like to generate?" << std::endl;
					std::cout << "all/threshold" << std::endl;
					std::cin >> buffer;

				} while (!std::cin.fail() && buffer != "all" && buffer != "threshold");

				if (buffer == "all") {

					writer.writeReport("allReport.txt", 0);
				}
				else {
					std::cout << "Enter threshold for report" << std::endl;
					std::cin >> buffer;

					writer.writeReport("threshReport.txt", stoi(buffer));
				}
				system("cls");
				mainMenu.print();
			}
			else {
				system("cls");
				mainMenu.print();
				std::cout << "no course list loaded" << std::endl;
				
			}
			
			break;
		case 6:
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