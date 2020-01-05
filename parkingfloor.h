#pragma once
#include <iostream>
#include "ParkingDisplayBoard.h"
#include "ParkingSpot.h"
#include "idgenerator.h"

using namespace std;
struct ParkedInfo
{
	unsigned int floorId;
	unsigned int spotId;

};
class ParkingFloor {
	unsigned int id;
	ParkingDisplayBoard* displayBoard;
	Idgenerator spotIdGenrator;

	unordered_map<unsigned int, ParkingSpotI*> handicappedSpots;
	unordered_map<unsigned int, ParkingSpotI*> compactSpots;
	unordered_map<unsigned int, ParkingSpotI*> largeSpots;
	unordered_map<unsigned int, ParkingSpotI*> motorbikeSpots;

	bool isAnySpotFree(unordered_map<unsigned int, ParkingSpotI*> spots);
	ParkingSpotI* getSpotById(unsigned int id);
	ParkingSpotI* getSpotByVehicleNumber(string vehicleNumber);
	unsigned int freeSpotCount(unordered_map<unsigned int, ParkingSpotI*> spots);
	void updateBoard();
public:
	ParkingFloor();

	void setId(unsigned int id)
	{
		this->id = id;
	}
	unsigned int getId() {
		return id;
	}
	void setDisplayBoard(ParkingDisplayBoard* displayBoard) 
	{ 
		this->displayBoard = displayBoard; 
	}

	void addParkingSpot(ParkingSpotI* spot);

	bool assignVehicleToSpot(ParkingSpotI* spot, string vehicleNumber, ParkedInfo& parkedInfo);
	bool assignVehicleToSpot(unsigned int spotId, string vehicleNumber, ParkedInfo& parkedInfo);
	bool assignVehicleToSpot(ParkingSpotType type,string vehicleNumber, ParkedInfo& parkedInfo);
	bool freeSpot(ParkingSpotI* spot, ParkedInfo& parkedInfo);
	bool freeSpot(unsigned int spotId, ParkedInfo& parkedInfo);
	bool freeSpot(string vehicleNumber, ParkedInfo& parkedInfo);
	
	unsigned int getFreeParkingSpotCount(ParkingSpotType type);
	unsigned int getTotalFreeParkingSpotCount();

	void printBoard();
};

