#pragma once
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class ParkingDisplayBoard
{
	//type : count
	vector<pair<string, unsigned int>> spotInfo;
	unsigned int id;
public:
	ParkingDisplayBoard(unsigned int id);
	void setId(unsigned int id);
	unsigned int getId();
	void set(vector<pair<string, unsigned int>> spotInfo);
	void display();
};

