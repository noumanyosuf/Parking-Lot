#pragma once
#include <iostream>
#include"vehicle.h"
#include <chrono>
#include <time.h>

using namespace std;
typedef chrono::high_resolution_clock::time_point TIME_POINT;

enum ParkingTicketStatus {
	UNPAID = 0, PAID, INACTIVE
};

class Address {
public:
	string streetAddress;
	string city;
	string state;
	string zipCode;
	string country;
};

class Person {
public:
	string name;
	Address address;
	string email;
	string phone;
};

class ParkingTicket
{
	struct VehicleInfo {
		string vehicleNumber;
		VehicleType vehicleType;
	}vehicleInfo;
	TIME_POINT  issuedAtTimePoint; string issuedAt;
	TIME_POINT  paidAtTimePoint; string paidAt;
	unsigned int ticketNumber;
	ParkingTicketStatus status;
public:	
	ParkingTicket(unsigned int ticketNumber);
	VehicleType getVehicleType() { return vehicleInfo.vehicleType; }
	string getVehicleNumber() { return vehicleInfo.vehicleNumber; }
	TIME_POINT getIssuedTime() { return issuedAtTimePoint; }

	void setVehicleInfo(string vehicleNumber, VehicleType vehicleType);
	void setTicketStatus(ParkingTicketStatus status);
	void setIssusedTime();
	void setPaidTIme();
	void printTicket();
};
