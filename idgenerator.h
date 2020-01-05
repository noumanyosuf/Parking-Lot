#pragma once
#include <iostream>

class Idgenerator
{
	unsigned int currentId;
public:
	Idgenerator() :currentId(0) {}
	unsigned int getNextId() { return currentId++; }
};