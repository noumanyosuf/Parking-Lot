#include "parkinglot.h"

ParkingLot* ParkingLot::instance = nullptr;

bool ParkingLot::isFull(VehicleType type)
{
	ParkingSpotType slotType;
	switch (type)
	{
	case CAR:
		slotType = MEDIUM;
		break;
	case TRUCK:
		slotType = LARGE;
		break;
	case VAN:
		slotType = MEDIUM;
		break;
	case MOTORBIKE:
		slotType = COMPACT;
		break;
	default:
		cout << "Vehicle type not found" << endl;
		return false;
	}
	return this->getFreeParkingSpotCount(slotType);
}

void ParkingLot::searchParkedVehicleInfo(string vehicleNumber)
{
	for (auto itr = activeParkedVehicle.begin(); itr != activeParkedVehicle.end(); ++itr)
	{
		if ((itr->first) == vehicleNumber)
		{
			cout << "Vehicle number " << vehicleNumber << " is parked at floor id" << (itr->second).floorId << " and spot id " << (itr->second).spotId << endl;
		}
	}
	cout << "Information for vehicle " << vehicleNumber << " could be found" << endl;
}

void ParkingLot::printBoards()
{
	for (auto itr = parkingFloors.begin(); itr != parkingFloors.end(); ++itr)
	{
		if (nullptr != (itr->second))
		{
			(itr->second)->printBoard();
		}
	}
}

ParkingLot* ParkingLot::getInstance()
{
	if (instance == nullptr)
		instance = new ParkingLot();
	return instance;
}

void ParkingLot::addParkingFloor(ParkingFloor* floor)
{
	if (nullptr == floor)
	{
		return;
	}
	floor->setId(floorIdGenrator.getNextId());
	parkingFloors[floor->getId()] = floor;
}

void ParkingLot::addParkingSpot(unsigned int floorId, ParkingSpotI* spot)
{
	auto status = parkingFloors.find(floorId);
	if (status != parkingFloors.end())
	{
		parkingFloors[floorId]->addParkingSpot(spot);
	}
}

void ParkingLot::addParkingDisplayBoard(unsigned int floorId, ParkingDisplayBoard* displayBoard)
{
	if (nullptr == displayBoard)
	{
		return;
	}
	auto status = parkingFloors.find(floorId);
	if (status != parkingFloors.end())
	{
		parkingFloors[floorId]->setDisplayBoard(displayBoard);
	}
}

void ParkingLot::removeParkingFloor(ParkingFloor* floor)
{
	if (nullptr == floor)
	{
		return;
	}
	parkingFloors.erase(floor->getId());
}

void ParkingLot::addEntrancePanel(EntrancePanel* entrancePanel)
{
	this->entrancePanel = entrancePanel;
}

void ParkingLot::removeEntrancePanel(EntrancePanel* entrancePanel)
{
	if (entrancePanel)
		delete entrancePanel;
	entrancePanel = nullptr;
}

void ParkingLot::addExitPanel(ExitPanel* exitPanel)
{
	this->exitPanel = exitPanel;
}

void ParkingLot::removeExitPanel(ExitPanel* exitPanel)
{
	if (exitPanel)
		delete exitPanel;
	exitPanel = nullptr;
}

bool ParkingLot::parkVehicle(ParkingSpotType type, string vehicleNumber)
{
	ParkedInfo parkedInfo;
	for (auto itr = parkingFloors.begin(); itr != parkingFloors.end(); ++itr)
	{
		if ( nullptr != (itr->second) && (itr->second)->assignVehicleToSpot(type, vehicleNumber, parkedInfo))
		{
			activeParkedVehicle[vehicleNumber] = parkedInfo;
			return true;
		}
	}
	cout << "Sorry no space for vechile type : " << type << "."<<endl;
	return false;
}

bool ParkingLot::freeVehicle(string vehicleNumber)
{
	ParkedInfo parkedInfo;
	for (auto itr = parkingFloors.begin(); itr != parkingFloors.end(); ++itr)
	{
		if (nullptr != (itr->second) && (itr->second)->freeSpot(vehicleNumber, parkedInfo))
		{
			activeParkedVehicle.erase(vehicleNumber);
			return true;
		}
	}
	cout << "Sorry no vechile with number " << vehicleNumber <<" avilable."<< endl;
	return false;
}

void ParkingLot::scanTicket(string vechileNumber)
{
	if (exitPanel)
	{
		exitPanel->scanTicket(ParkingTicketManager::getTicket(vechileNumber));
	}
}

void ParkingLot::processTicket(string vechileNumber, PaymentMode mode)
{
	if (exitPanel)
	{
		exitPanel->processPayment(ParkingTicketManager::getTicket(vechileNumber), mode);
	}
}

unsigned int ParkingLot::getTotalFreeParkingSpotCount()
{
	int count = 0;
	for (auto itr = parkingFloors.begin(); itr != parkingFloors.end(); ++itr)
	{
		if (nullptr != (itr->second))
		{
			count += (itr->second)->getTotalFreeParkingSpotCount();
		}
	}
	return count;
}

unsigned int ParkingLot::getFreeParkingSpotCount(ParkingSpotType type)
{
	int count = 0;
	for (auto itr = parkingFloors.begin(); itr != parkingFloors.end(); ++itr)
	{
		if (nullptr != (itr->second))
		{
			count += (itr->second)->getFreeParkingSpotCount(type);
		}
	}
	return count;
}
