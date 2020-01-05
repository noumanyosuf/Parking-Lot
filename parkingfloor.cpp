#include "parkingfloor.h"

bool ParkingFloor::isAnySpotFree(unordered_map<unsigned int, ParkingSpotI*> spots)
{
	for (auto it = spots.begin(); it != spots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->IsFree())
		{
			return true;
		}
	}
	return false;
}

ParkingSpotI* ParkingFloor::getSpotById(unsigned int id)
{
	ParkingSpotI* spot = nullptr;
	if (handicappedSpots.find(id) != handicappedSpots.end())
	{
		spot = handicappedSpots[id];
	}
	else if (compactSpots.find(id) != compactSpots.end())
	{
		spot = compactSpots[id];
	}
	else if (largeSpots.find(id) != largeSpots.end())
	{
		spot = largeSpots[id];
	}
	else if (motorbikeSpots.find(id) != motorbikeSpots.end())
	{
		spot = motorbikeSpots[id];
	}
	return spot;
}

ParkingSpotI* ParkingFloor::getSpotByVehicleNumber(string vehicleNumber)
{
	ParkingSpotI* spot = nullptr;
	for (auto it = handicappedSpots.begin(); it != handicappedSpots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->getVehicleNumber() == vehicleNumber)
		{
			spot = (it->second);
			return spot;
		}
	}

	for (auto it = compactSpots.begin(); it != compactSpots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->getVehicleNumber() == vehicleNumber)
		{
			spot = (it->second);
			return spot;
		}
	}

	for (auto it = largeSpots.begin(); it != largeSpots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->getVehicleNumber() == vehicleNumber)
		{
			spot = (it->second);
			return spot;
		}
	}

	for (auto it = motorbikeSpots.begin(); it != motorbikeSpots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->getVehicleNumber() == vehicleNumber)
		{
			spot = (it->second);
			return spot;
		}
	}
	return spot;
}

unsigned int ParkingFloor::freeSpotCount(unordered_map<unsigned int, ParkingSpotI*> spots)
{
	unsigned int count = 0;
	for (auto it = spots.begin(); it != spots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->IsFree())
		{
			count++;
		}
	}
	return count;
}

ParkingFloor::ParkingFloor():displayBoard(nullptr)
{
}

void ParkingFloor::addParkingSpot(ParkingSpotI* spot)
{
	if (nullptr == spot)
	{
		return;
	}
	switch (spot->getType())
	{
	case ParkingSpotType::HANDICAPPED:
		handicappedSpots[spot->getId()] = spot;
		break;
	case ParkingSpotType::COMPACT:
		compactSpots[spot->getId()] = spot;
		break;
	case ParkingSpotType::LARGE:
		largeSpots[spot->getId()] = spot;
		break;
	case ParkingSpotType::MEDIUM:
		motorbikeSpots[spot->getId()] = spot;
		break;
	default:
		cout << "Wrong parking spot type!" << endl;
	}
	spot->setId(spotIdGenrator.getNextId());
}

bool ParkingFloor::assignVehicleToSpot(ParkingSpotI* spot, string vehicleNumber, ParkedInfo& parkedInfo)
{
	if (nullptr == spot)
	{
		return false;
	}
	bool bSpotAvailable = false;
	switch (spot->getType())
	{
	case ParkingSpotType::HANDICAPPED:
		bSpotAvailable = isAnySpotFree(handicappedSpots);
		break;
	case ParkingSpotType::COMPACT:
		bSpotAvailable = isAnySpotFree(compactSpots);
		break;
	case ParkingSpotType::LARGE:
		bSpotAvailable = isAnySpotFree(largeSpots);
		break;
	case ParkingSpotType::MEDIUM:
		bSpotAvailable = isAnySpotFree(motorbikeSpots);
		break;
	default:
		cout << "Wrong parking spot type!" << endl;
		return false;
	}
	if (!bSpotAvailable)
	{
		return false;
	}
	spot->assignVehicle(vehicleNumber);
	parkedInfo.floorId = this->id;
	parkedInfo.spotId = spot->getId();
	printBoard();
	return true;
}

bool ParkingFloor::assignVehicleToSpot(unsigned int spotId, string vehicleNumber, ParkedInfo& parkedInfo)
{
	ParkingSpotI* spot = getSpotById(spotId);
	if (spot == nullptr)
	{
		return false;
	}
	return assignVehicleToSpot(spot, vehicleNumber, parkedInfo);
}

bool ParkingFloor::assignVehicleToSpot(ParkingSpotType type, string vehicleNumber, ParkedInfo& parkedInfo)
{
	unordered_map<unsigned int, ParkingSpotI*> spots;
	switch (type)
	{
	case ParkingSpotType::HANDICAPPED:
		spots = handicappedSpots;
		break;
	case ParkingSpotType::COMPACT:
		spots = compactSpots;
		break;
	case ParkingSpotType::LARGE:
		spots = largeSpots;
		break;
	case ParkingSpotType::MEDIUM:
		spots = motorbikeSpots;
		break;
	default:
		cout << "Wrong parking spot type!" << endl;
		return false;
	}
	for (auto it = spots.begin(); it != spots.end(); ++it)
	{
		if (nullptr != (it->second) && (it->second)->IsFree())
		{
			(it->second)->assignVehicle(vehicleNumber);
			cout << "Vehicle " << vehicleNumber << " added to floor with id "<<this->id << endl;
			parkedInfo.floorId = this->id;
			parkedInfo.spotId = (it->second)->getId();
			printBoard();
			return true;;
		}
	}
	return false;
}

bool ParkingFloor::freeSpot(ParkingSpotI* spot, ParkedInfo& parkedInfo)
{
	if (nullptr == spot)
	{
		return false;
	}
	string vehicleNumber = spot->getVehicleNumber();
	spot->removeVehicle();
	parkedInfo.floorId = this->id;
	parkedInfo.spotId = spot->getId();
	cout << "Vehicle " << vehicleNumber << " removed from floor with id " << this->id << endl;
	printBoard();
	return true;
}

bool ParkingFloor::freeSpot(unsigned int spotId, ParkedInfo& parkedInfo)
{
	ParkingSpotI* spot = getSpotById(spotId);
	if (spot == nullptr)
	{
		return false;
	}
	return freeSpot(spot, parkedInfo);
}

bool ParkingFloor::freeSpot(string vehicleNumber, ParkedInfo& parkedInfo)
{
	ParkingSpotI* spot = getSpotByVehicleNumber(vehicleNumber);
	if (spot == nullptr)
	{
		return false;
	}
	return freeSpot(spot, parkedInfo);
}

void ParkingFloor::updateBoard()
{
	vector<pair<string, unsigned int>> spotInfo;
	spotInfo.push_back(pair<string, unsigned int>("Handicapped Spot", freeSpotCount(handicappedSpots)));
	spotInfo.push_back(pair<string, unsigned int>("Compact Spot", freeSpotCount(compactSpots)));
	spotInfo.push_back(pair<string, unsigned int>("Large Spot", freeSpotCount(largeSpots)));
	spotInfo.push_back(pair<string, unsigned int>("Moterbike Spot", freeSpotCount(motorbikeSpots)));
	displayBoard->set(spotInfo);
}

unsigned int ParkingFloor::getFreeParkingSpotCount(ParkingSpotType type)
{
	unordered_map<unsigned int, ParkingSpotI*> spots;
	switch (type)
	{
	case ParkingSpotType::HANDICAPPED:
		spots = handicappedSpots;
		break;
	case ParkingSpotType::COMPACT:
		spots = compactSpots;
		break;
	case ParkingSpotType::LARGE:
		spots = largeSpots;
		break;
	case ParkingSpotType::MEDIUM:
		spots = motorbikeSpots;
		break;
	default:
		cout << "Wrong parking spot type!" << endl;
		return -1;
	}
	return freeSpotCount(spots);
}

unsigned int ParkingFloor::getTotalFreeParkingSpotCount()
{
	unsigned int count = freeSpotCount(handicappedSpots);
	count += freeSpotCount(compactSpots);
	count += freeSpotCount(largeSpots);
	count += freeSpotCount(motorbikeSpots);
	return count;
}

void ParkingFloor::printBoard()
{
	cout << " Display board of floor with id : " << this->id << endl;
	updateBoard();
	displayBoard->display();
}
