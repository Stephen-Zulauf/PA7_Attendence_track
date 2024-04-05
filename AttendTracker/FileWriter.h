#pragma once

#include "config.h"
#include "Data.h"
#include "List.h"
#include "Node.h"

class FileWriter {
private:
	List<Node<Data>>* mList;
public:
	FileWriter(List<Node<Data>>* nList) {
		this->mList = nList;
	}
	FileWriter(FileWriter& copy) {
		this->mList = copy.mList;
	}
	~FileWriter() {
	}

	//members
	bool writeFile(std::string nFileName);

	void writeReport(std::string nFileName, int type);



};