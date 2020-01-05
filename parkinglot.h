#pragma once
#include <iostream>
#include "parkingfloor.h"
#include "parkingticket.h"
#include "vehicle.h"
#include  "panel.h"
#include "idgenerator.h"
using namespace std;

class ParkingLot
{
	static ParkingLot* instance;
	Idgenerator floorIdGenrator;
	//vehicle number,<floor id, spot id> // to search active parked vechiles by vechile number
	unordered_map<string, ParkedInfo> activeParkedVehicle;
	Address address;
	EntrancePanel* entrancePanel;
	ExitPanel* exitPanel;
	unordered_map<unsigned int, ParkingFloor*> parkingFloors;
	ParkingLot() {};
public:
	static ParkingLot* getInstance();
	//admins options
	void addParkingFloor(ParkingFloor* floor);
	void addParkingSpot(unsigned int floorId, ParkingSpotI* spot);
	void addParkingDisplayBoard(unsigned int floorId, ParkingDisplayBoard* displayBoard);
	void removeParkingFloor(ParkingFloor* floor);
	void addEntrancePanel(EntrancePanel* entrancePanel);
	void removeEntrancePanel(EntrancePanel* entrancePanel);
	void addExitPanel(ExitPanel* exitPanel);
	void removeExitPanel(ExitPanel* exitPanel);

	//operater options
	bool parkVehicle(ParkingSpotType type,string vehicleNumber);
	bool freeVehicle(string vehicleNumber);
	void scanTicket(string vechileNumber);
	void processTicket(string vechileNumber,PaymentMode mode);

	unsigned int getTotalFreeParkingSpotCount();
	unsigned int getFreeParkingSpotCount(ParkingSpotType type);
	bool isFull(VehicleType type);

	void searchParkedVehicleInfo(string vehicleNumber);
	void printBoards();
};

