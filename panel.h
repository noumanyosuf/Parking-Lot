#pragma once
#include<iostream>
#include "parkingticketmanager.h"
#include "paymentManager.h"

class EntrancePanel
{
	unsigned int id;
public:
	void setId(unsigned int id)
	{
		this->id = id;
	}
	unsigned int getId() {
		return id;
	}
	ParkingTicket* getTicket(string vehicleNumber, VehicleType vehicleType);
};

class ExitPanel
{
	unsigned int id;
public:
	void setId(unsigned int id)
	{
		this->id = id;
	}
	unsigned int getId() {
		return id;
	}
	void scanTicket(ParkingTicket* ticket);
	void processPayment(ParkingTicket* ticket,PaymentMode mode);
};

