#include "Data.h"

void Data::setRecordNum(int nNum) {
	this->recordNum = nNum;
}
void Data::setIDNum(std::string& nNum) {
	this->ID = stoi(nNum);

}
void Data::setlName(std::string& nName) {
	this->lastName = nName;

}
void Data::setfName(std::string& nName) {
	this->firstName = nName;

}
void Data::setEmail(std::string& nEmail) {
	this->email = nEmail;

}
void Data::setUnits(std::string& nUnits) {
	this->units = nUnits;
}
void Data::setMajor(std::string& nMajor) {
	this->major = nMajor;

}
void Data::setLevel(std::string& nLevel) {
	this->level = nLevel;

}
/*
int recordNum = 0;
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

std::ostream& operator <<(std::ostream& out, const Data& data) {
	std::cout << data.recordNum << std::endl;
	std::cout << data.ID << std::endl;
	std::cout << data.lastName << std::endl;
	std::cout << data.firstName << std::endl;
	std::cout << data.email << std::endl;
	std::cout << data.units << std::endl;
	std::cout << data.major << std::endl;
	std::cout << data.level << std::endl;

	return out;
};

void Data::print() const{
	std::cout << this->recordNum << std::endl;
	std::cout << this->ID << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->firstName << std::endl;
	std::cout << this->email << std::endl;
	std::cout << this->units << std::endl;
	std::cout << this->major << std::endl;
	std::cout << this->level << std::endl;
}