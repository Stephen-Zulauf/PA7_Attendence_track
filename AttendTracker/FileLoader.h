#pragma once

#include "config.h"
#include "Data.h"
#include "List.h"
#include "Node.h"

class FileLoader {
private:
	std::string fileName;
	List<Node<Data>>* mList;
public:
	FileLoader(std::string nFileName, List<Node<Data>>* nList) {
		this->fileName = nFileName;
		this->mList = nList;
	}
	FileLoader(FileLoader& copy) {
		this->fileName = copy.fileName;
		this->mList = copy.mList;
	}
	~FileLoader() {
	}

	//members
	bool loadFile();



};