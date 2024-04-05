//#include "FileLoader.h"
//
//
////members
//bool FileLoader::loadFile(std::string nFileName) {
//
//	std::ifstream inputFile;
//	inputFile.open(nFileName);
//
//	if (inputFile.is_open()) {
//		//buffer
//		std::string tmpLine;
//
//		//tmp data
//		Data* tmpData = nullptr;
//
//		//prev
//		Node<Data>* prevNode = nullptr;
//		
//		//track data entry number
//		int num = 0;
//
//		//remove header
//		std::getline(inputFile, tmpLine, '\n');
//
//		//read data (while s'all good bra)
//		while (inputFile.good()) {
//			//create new data object
//			tmpData = new Data;
//
//			//error check creation of nodes/data
//			if (!tmpData) {
//				std::cout << "ERR FILELOADER: Couldn't create Data:"
//					<< "\'" << num << "\'" << std::endl;
//
//				//close file
//				inputFile.close();
//
//				return false;
//			}
//
//			//get record num
//			std::getline(inputFile, tmpLine, ',');
//
//			//check if blank line before EOF
//			if (tmpLine.empty()) {
//				break;
//			}
//
//			//std::cout << tmpLine << std::endl;
//			tmpData->setRecordNum(num);
//
//			//get ID num
//			std::getline(inputFile, tmpLine, ',');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setIDNum(tmpLine);
//			
//			//get last name
//			std::getline(inputFile, tmpLine, ',');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setlName(tmpLine);
//			//get first name
//			std::getline(inputFile, tmpLine, ',');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setfName(tmpLine);
//
//			//get email
//			std::getline(inputFile, tmpLine, ',');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setEmail(tmpLine);
//
//			//get units
//			std::getline(inputFile, tmpLine, ',');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setUnits(tmpLine);
//
//			//get program
//			std::getline(inputFile, tmpLine, ',');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setMajor(tmpLine);
//
//			//get level
//			std::getline(inputFile, tmpLine, '\n');
//			//std::cout << tmpLine << std::endl;
//			tmpData->setLevel(tmpLine);
//
//			//push node to list
//			prevNode = new Node<Data>(tmpData, prevNode);
//			this->mList->push(prevNode);
//			
//			//advance
//			num += 1;
//
//		}
//		
//		//close file
//		inputFile.close();
//
//	}
//	else {
//		std::cout << "ERR FILELOADER: Couldn't open file:" 
//			<< "\'" << nFileName << "\'" << std::endl;
//		return false;
//	}
//
//	return true;
//
//}