#pragma once

#include "config.h"
#include "Stack.h"

class Data {
private:
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
	Stack* datesAbsence = nullptr;

public:
	Data() {
		datesAbsence = new Stack;
	}
	Data(Data& copy) {
		this->recordNum = copy.recordNum;
		this->ID = copy.ID;
		this->lastName = copy.lastName;
		this->firstName = copy.firstName;
		this->email = copy.email;
		this->units = copy.units;
		this->major = copy.major;
		this->level = copy.level;
		this->numAbsence = numAbsence;
		this->datesAbsence = new Stack(*copy.datesAbsence);

	}
	~Data() {
		if (datesAbsence) {
			delete datesAbsence;
		}
		//std::cout << "Data destructor called" << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Data& data);

	void setRecordNum(int nNum);
	void setIDNum(std::string& nNum);
	void setlName(std::string& nlName);
	void setfName(std::string& nfName);
	void setEmail(std::string& nEmail);
	void setUnits(std::string& nUnits);
	void setMajor(std::string& nMajor);
	void setLevel(std::string& nLevel);

	void print() const;

};



