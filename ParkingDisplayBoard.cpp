#include "ParkingDisplayBoard.h"

ParkingDisplayBoard::ParkingDisplayBoard(unsigned int id)
{
	this->id = id;
}

void ParkingDisplayBoard::setId(unsigned int id)
{
	this->id = id;
}

unsigned int ParkingDisplayBoard::getId()
{
	return id;
}

void ParkingDisplayBoard::set(vector<pair<string, unsigned int>> spotInfo)
{
	this->spotInfo = spotInfo;
}

void ParkingDisplayBoard::display()
{
	//display spot info
	cout << endl;
	cout << "\t" << "**** Display ****" << endl;
	for (auto it = spotInfo.begin(); it != spotInfo.end(); ++it)
	{
		cout << "\t" << (*it).first << " : " << (*it).second << endl;
	}
	cout << "\t" << "*****************" << endl;
	cout << endl;
}
