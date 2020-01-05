#include "panel.h"
#include "paymentManager.h"
#include "parkingratemanager.h"
#include <chrono>
#include <time.h>

ParkingTicket* EntrancePanel::getTicket(string vehicleNumber, VehicleType vehicleType)
{
	return ParkingTicketManager::printTicket(vehicleNumber, vehicleType);
}

void ExitPanel::scanTicket(ParkingTicket* ticket)
{
	if (nullptr != ticket)
	{
		cout << "Scaned ticket is " << endl;
		ticket->printTicket();
	}
	else
	{
		cout << "Could not scan ticket" << endl;
	}
}

void ExitPanel::processPayment(ParkingTicket* ticket, PaymentMode mode)
{
	if (nullptr != ticket)
	{
		double totalTime = (std::chrono::duration<double, std::milli>(ticket->getIssuedTime() - std::chrono::high_resolution_clock::now()).count());
		totalTime = totalTime / 36000; // convert to hours
		double amount = ParkingRateManager::getRate(ticket->getVehicleType()) * totalTime;
		PaymentManager::makePayment(mode, amount);
		ticket->setTicketStatus(ParkingTicketStatus::PAID);
		ticket->setPaidTIme();
		ParkingTicketManager::removeTicket(ticket->getVehicleNumber());
	}
	else
	{
		cout << "Could not prccess the payment for the ticket" << endl;
	}
}
