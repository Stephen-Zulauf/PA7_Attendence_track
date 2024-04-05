#include "FileWriter.h"

/*int recordNum = 0;
int ID = 0;
//last first
std::string lastName;
std::string firstName;
std::string email;
std::string units;
std::string major;
std::string level;

//absence info
int numAbsence = 0;
Stack datesAbsence;
*/

//members
bool FileWriter::writeFile(std::string nFileName) {
	std::ofstream outFile;
	outFile.open(nFileName);

	if (outFile.is_open()) {
		//write header
		outFile << ",ID,Name,Email,Units,Program,Level" << '\n';

		//write record per line
		while(this->mList->getSize() > 0) {
			Node<Data>* temp = this->mList->peek();
			outFile << temp->getData()->getRecordNum();
			outFile << ",";
			outFile << temp->getData()->getIDNum();
			outFile << ",";
			outFile << temp->getData()->getlName();
			outFile << ",";
			outFile << temp->getData()->getfName();
			outFile << ",";
			outFile << temp->getData()->getEmail();
			outFile << ",";
			outFile << temp->getData()->getUnits();
			outFile << ",";
			outFile << temp->getData()->getMajor();
			outFile << ",";
			outFile << temp->getData()->getLevel();
			outFile << ",";
			outFile << "[";
			Stack* tempStack = temp->getData()->getAbs();
			while (!tempStack->isEmpty()) {
				std::string test = tempStack->pop();
				std::cout << "testWrite: " << test << std::endl;
				outFile << test;
				outFile << ",";
			}
			outFile << "]";
			/*if (temp->getData()->hasAbs()) {
				
			}*/
			outFile << "\n";
			//pop node;
			this->mList->pop();
		}

		outFile.close();
		return true;
	}
	else {
		std::cout << "ERR: FileWriter could not open file" << std::endl;
		return false;
	}
}

void FileWriter::writeReport(std::string nFileName, int type) {
	std::ofstream outFile(nFileName);

	Node<Data>* temp = this->mList->peek();

	if (outFile.is_open()) {

		if (type == 0) {
			//write header
			outFile << "Report: All students" << '\n';

			//write record per line
			while (temp) {
				
				outFile << "------------------------" << std::endl;
				outFile << temp->getData()->getIDNum() << std::endl;
				outFile << temp->getData()->getfName();
				outFile << ",";
				outFile << temp->getData()->getlName() << std::endl;
				outFile << "Last Absence: ";
				
				Stack* tempStack = temp->getData()->getAbs();
				outFile << tempStack->peek() << std::endl;
				outFile << "------------------------" << std::endl;

				temp = temp->getNext();
			}
			/*std::cout << "creating file" << std::endl;*/
		}
		else {
			//write header
			outFile << "Report: Threshold" << '\n';

			//write record per line
			while (temp) {
				if (temp->getData()->getNumAbs() > type) {
					outFile << "------------------------" << std::endl;
					outFile << temp->getData()->getIDNum() << std::endl;
					outFile << temp->getData()->getfName();
					outFile << ",";
					outFile << temp->getData()->getlName() << std::endl;
					outFile << "Number of Absences: " << temp->getData()->getNumAbs() << std::endl;
					outFile << "Last Absence: ";

					Stack* tempStack = temp->getData()->getAbs();
					outFile << tempStack->peek() << std::endl;
					outFile << "------------------------" << std::endl;
				}
				
				temp = temp->getNext();
			}
			/*std::cout << "creating file" << std::endl;*/
		}
		

		outFile.close();
	}
}