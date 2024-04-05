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
void Data::newAbs(std::string nAbs) {
	this->datesAbsence->push(nAbs);
	this->numAbsence += 1;
	//std::cout << "num of abs" << this->numAbsence << std::endl;
}

//getter
int Data::getRecordNum() const {
	return this->recordNum;
}
int Data::getIDNum() const {
	return this->ID;
}
std::string Data::getlName() const {
	return this->lastName;
}
std::string Data::getfName() const {
	return this->firstName;
}
std::string Data::getEmail() const {
	return this->email;
}
std::string Data::getUnits() const {
	return this->units;
}
std::string Data::getMajor() const {
	return this->major;
}
std::string Data::getLevel() const {
	return this->level;
}
int Data::getNumAbs() const {
	return this->numAbsence;
}
bool Data::hasAbs() const {
	return this->datesAbsence->isEmpty();
}
Stack* Data::getAbs() const {
	return this->datesAbsence;
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
	this->datesAbsence->print();

}