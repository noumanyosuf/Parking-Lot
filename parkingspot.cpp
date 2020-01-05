#include "ParkingSpot.h"

ParkingSpotI::ParkingSpotI(ParkingSpotType type)
{
	this->type = type;
}

void ParkingSpotI::assignVehicle(string vehicleNumber)
{
	free = false;
	this->vehicleNumber = vehicleNumber;
}

void ParkingSpotI::removeVehicle()
{
	this->vehicleNumber = "";
	free = true;
}
