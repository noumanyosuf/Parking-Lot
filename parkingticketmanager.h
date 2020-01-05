#pragma once
#include "parkingticket.h"
#include "idgenerator.h"
#include <unordered_map>

class ParkingTicketManager
{
	ParkingTicketManager() = delete;
	ParkingTicketManager(const ParkingTicketManager&) = delete;
	static unordered_map<string, ParkingTicket*> activeTickets;
	static Idgenerator idGenrator;
public:
	static ParkingTicket* printTicket(string vehicleNumber, VehicleType vehicleType);
	static void removeTicket(string vehicleNumber);
	static ParkingTicket* getTicket(string vehicleNumber);
};

