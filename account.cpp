#include "account.h"


IAccount::IAccount()
{
	parkingLot = ParkingLot::getInstance();
}

void Admin::addParkingFloor(ParkingFloor* floor)
{
	if (nullptr != parkingLot)
	{
		parkingLot->addParkingFloor(floor);
	}
}

void Admin::addParkingSpot(unsigned int floorId, ParkingSpotI* spot)
{
	if (nullptr != parkingLot)
	{
		parkingLot->addParkingSpot(floorId, spot);
	}
}

void Admin::addParkingDisplayBoard(unsigned int floorId, ParkingDisplayBoard* displayBoard)
{
	if (nullptr != parkingLot)
	{
		parkingLot->addParkingDisplayBoard(floorId, displayBoard);
	}
}

void Admin::addEntrancePanel(EntrancePanel* entrancePanel)
{
	if (nullptr != parkingLot)
	{
		parkingLot->addEntrancePanel(entrancePanel);
	}
}

void Admin::addExitPanel(ExitPanel* exitPanel)
{
	if (nullptr != parkingLot)
	{
		parkingLot->addExitPanel(exitPanel);
	}
}

void ParkingAttendant::scanTicket(string vechileNumber)
{
	if (nullptr != parkingLot)
	{
		parkingLot->scanTicket(vechileNumber);
	}
}

void ParkingAttendant::processTicket(string vechileNumber, PaymentMode mode)
{
	if (nullptr != parkingLot)
	{
		parkingLot->processTicket(vechileNumber, mode);
	}
}

void ParkingAttendant::searchParkedVehicleInfo(string vehicleNumber)
{
	if (nullptr != parkingLot)
	{
		parkingLot->searchParkedVehicleInfo(vehicleNumber);
	}
}

