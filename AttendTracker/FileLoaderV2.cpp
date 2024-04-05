#include "FileLoaderV2.h"


//members
bool FileLoader::loadFile(std::string nFileName) {

	std::ifstream inputFile;
	inputFile.open(nFileName);

	if (inputFile.is_open()) {
		//buffer
		std::string buffer;
		std::string subBuffer;
		size_t index = 0;
		size_t subIndex = 0;

		//tmp data
		Data* tmpData = nullptr;

		//prev
		Node<Data>* prevNode = nullptr;

		//track data entry number
		int num = 0;

		//remove header
		std::getline(inputFile, buffer, '\n');

		//read data (while s'all good bra)
		while (inputFile.good()) {
			//create new data object
			tmpData = new Data;

			//error check creation of nodes/data
			if (!tmpData) {
				std::cout << "ERR FILELOADER: Couldn't create Data:"
					<< "\'" << num << "\'" << std::endl;

				//close file
				inputFile.close();

				return false;
			}

			//get student line
			std::getline(inputFile, buffer, '\n');

			//break if empty line
			if (buffer.empty()) {
				break;
			}
			//if dates array is present
			else if (buffer.find("[") != std::string::npos) {

				//set record number
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setRecordNum(atoi(subBuffer.c_str()));
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);
				

				//get ID num
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setIDNum(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);
				

				//get last name
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setlName(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get first name
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setfName(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get email
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setEmail(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get units
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setUnits(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get program
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setMajor(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get level
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setLevel(subBuffer);
				//std::cout << "dates: " << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get absent dates
				
				index = buffer.find('[')+1;
				subIndex = buffer.find(']');
				subBuffer = buffer.substr(index, subIndex);

				size_t pos = 0;
				std::string date;
				while ((pos=subBuffer.find(',')) != std::string::npos) {
					date = subBuffer.substr(0, pos);
					tmpData->newAbs(date);
					//std::cout << "dates: " << date << std::endl;
					subBuffer.erase(0, pos + 1);
				}

				//push node to list
				prevNode = new Node<Data>(tmpData, prevNode);
				this->mList->push(prevNode);
			}
			//no dates array
			else {
				//set record number
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setRecordNum(atoi(subBuffer.c_str()));
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get ID num
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setIDNum(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);


				//get last name
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setlName(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get first name
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setfName(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get email
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setEmail(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get units
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setUnits(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get program
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setMajor(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//get level
				index = buffer.find(',');
				subBuffer = buffer.substr(0, index);
				tmpData->setLevel(subBuffer);
				//std::cout << subBuffer << std::endl;
				buffer.erase(0, index + 1);

				//push node to list
				prevNode = new Node<Data>(tmpData, prevNode);
				this->mList->push(prevNode);
			}

			//advance
			num += 1;

		}

		//close file
		inputFile.close();

	}
	else {
		std::cout << "ERR FILELOADER: Couldn't open file:"
			<< "\'" << nFileName << "\'" << std::endl;
		return false;
	}

	return true;

}