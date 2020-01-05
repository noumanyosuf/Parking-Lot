#pragma once
#include <iostream>
#include "parkingticket.h"
#include "panel.h"
#include "parkinglot.h"
using namespace std;

class IAccount {
protected:
	ParkingLot* parkingLot;
public:
	IAccount();
	string userName;
	string password;
	Person person;
};

class Admin : public IAccount {
	
public:
	using IAccount::parkingLot;
	void addParkingFloor(ParkingFloor* floor);
	void addParkingSpot(unsigned int floorId, ParkingSpotI* spot);
	void addParkingDisplayBoard(unsigned int floorId, ParkingDisplayBoard* displayBoard);
	void addEntrancePanel(EntrancePanel* entrancePanel);
	void addExitPanel(ExitPanel* exitPanel);
};

class ParkingAttendant : public IAccount {
public:
	void scanTicket(string vechileNumber);
	void processTicket(string vechileNumber, PaymentMode mode);
	void searchParkedVehicleInfo(string vehicleNumber);
};
