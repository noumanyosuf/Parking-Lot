#include "parkingticketmanager.h"
Idgenerator ParkingTicketManager::idGenrator;
unordered_map<string, ParkingTicket*> ParkingTicketManager::activeTickets;

ParkingTicket* ParkingTicketManager::printTicket(string vehicleNumber, VehicleType vehicleType)
{
	ParkingTicket*ticket=new ParkingTicket(ParkingTicketManager::idGenrator.getNextId());
	if (nullptr != ticket)
	{
		ticket->setIssusedTime();
		ticket->setTicketStatus(ParkingTicketStatus::UNPAID);
		ticket->setVehicleInfo(vehicleNumber, vehicleType);
		ParkingTicketManager::activeTickets[vehicleNumber] = ticket;
	}
	return ticket;
}

void ParkingTicketManager::removeTicket(string vehicleNumber)
{
	ParkingTicketManager::activeTickets.erase(vehicleNumber);
}

ParkingTicket* ParkingTicketManager::getTicket(string vehicleNumber)
{
	if (ParkingTicketManager::activeTickets.find(vehicleNumber) != ParkingTicketManager::activeTickets.end())
	{
		return ParkingTicketManager::activeTickets[vehicleNumber];
	}
	return nullptr;
}
