#include "parkingticket.h"
#include <ctime>

ParkingTicket::ParkingTicket(unsigned int ticketNumber)
{
	this->ticketNumber = ticketNumber;
	issuedAt = "";
	paidAt = "";
}

void ParkingTicket::setVehicleInfo(string vehicleNumber, VehicleType vehicleType)
{
	this->vehicleInfo.vehicleNumber = vehicleNumber;
	this->vehicleInfo.vehicleType = vehicleType;
}

void ParkingTicket::setTicketStatus(ParkingTicketStatus status)
{
	this->status = status;
}

void ParkingTicket::printTicket()
{
	cout << "*******Ticet**********" << endl;
	cout << "Ticket number  :" << ticketNumber << endl;
	cout << "Vehicle number :" << vehicleInfo.vehicleNumber << endl;
	cout << "Vehicle type   :" << vehicleInfo.vehicleType << endl;
	cout << "Issued at      :" << issuedAt << endl;
	cout << "Paid at        :" << ((paidAt=="")?"Not Paid": paidAt) << endl;
	cout << "Payment status :" << status << endl;
}

void ParkingTicket::setIssusedTime()
{
	char buffer[64];
	std::time_t  t = std::time(NULL);
	errno_t e = ctime_s(buffer, 64, &t);
	if (e) issuedAt = "";
	else   issuedAt = string(buffer);
	issuedAtTimePoint = std::chrono::high_resolution_clock::now();
}

void ParkingTicket::setPaidTIme()
{

	char buffer[64];
	std::time_t  t = std::time(NULL);
	errno_t e = ctime_s(buffer, 64, &t);
	if (e) paidAt="";
	else   paidAt= string(buffer);
	paidAtTimePoint = std::chrono::high_resolution_clock::now();
}
