#pragma once
#include <iostream>
using namespace std;

enum VehicleType
{
	CAR = 0, TRUCK, VAN, MOTORBIKE
};

class VehicleI {

public:
	VehicleI(VehicleType type) {
		this->type = type;
		vehicleNumber = "";
	}
	string vehicleNumber;
	VehicleType type;
};

class Car : public VehicleI {
public:
	Car() : VehicleI(VehicleType::CAR) {
	}
};

class Van : public VehicleI {
public:
	Van() : VehicleI(VehicleType::VAN) {
	}
};

class Truck : public VehicleI {
public:
	Truck() : VehicleI(VehicleType::TRUCK) {
	}
};

class Motorcycle : public VehicleI {
public:
	Motorcycle() : VehicleI(VehicleType::MOTORBIKE) {
	}
};
