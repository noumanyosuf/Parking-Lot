#pragma once
#include <iostream>
using namespace std;

enum ParkingSpotType {
	HANDICAPPED = 1, COMPACT, LARGE, MEDIUM
};

class ParkingSpotI {
	unsigned int id;
	bool free;
	ParkingSpotType type;
	string vehicleNumber;
public:
	ParkingSpotI(ParkingSpotType type);
	void assignVehicle(string vehicleNumber);
	string getVehicleNumber() { return this->vehicleNumber; }
	void setId(unsigned int id)
	{
		this->id = id;
	}
	unsigned int getId() {
		return id;
	}
	void removeVehicle();
	ParkingSpotType getType() {
		return type;
	}
	bool IsFree() {
		return free;
	}
};

class HandicappedSpot : public ParkingSpotI {
public:
	HandicappedSpot() :ParkingSpotI(ParkingSpotType::HANDICAPPED)
	{
	}
};

class CompactSpot : public  ParkingSpotI {
public:
	CompactSpot() : ParkingSpotI(ParkingSpotType::COMPACT) {
	}
};

class LargeSpot : public  ParkingSpotI {
public:
	LargeSpot() : ParkingSpotI(ParkingSpotType::LARGE) {
	}
};

class MotorbikeSpot : public  ParkingSpotI {
public:
	MotorbikeSpot() : ParkingSpotI(ParkingSpotType::MEDIUM) {
	}
};
