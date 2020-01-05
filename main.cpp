#include <iostream>
#include "account.h"
#include <memory.h>
using namespace std;

int main()
{
	EntrancePanel* entrancePanel = new EntrancePanel();
	ExitPanel* exitPanel = new ExitPanel();
	/*START : setting parking floors*/
	//parking floor 1
	unique_ptr<ParkingFloor> floor1 = unique_ptr<ParkingFloor>(new ParkingFloor());
	unique_ptr <ParkingDisplayBoard> displayBoard = unique_ptr <ParkingDisplayBoard>(new ParkingDisplayBoard(1));
	floor1->setDisplayBoard(displayBoard.get());
	int id = 0;
	for (int i = 0; i < 5; i++)
	{
		ParkingSpotI* spot1 = new HandicappedSpot;
		spot1->setId(id++);
		floor1->addParkingSpot(spot1);
	}
	for (int i = 0; i < 5; i++)
	{
		ParkingSpotI* spot1 = new CompactSpot;
		spot1->setId(id++);
		floor1->addParkingSpot(spot1);
	}
	//END : parking floor 1
	//START : parking floor 2
	unique_ptr<ParkingFloor> floor2 = unique_ptr<ParkingFloor>(new ParkingFloor());
	unique_ptr <ParkingDisplayBoard> displayBoard2 = unique_ptr <ParkingDisplayBoard>(new ParkingDisplayBoard(1));
	floor2->setDisplayBoard(displayBoard2.get());
	id = 0;
	for (int i = 0; i < 10; i++)
	{
		ParkingSpotI* spot1 = new HandicappedSpot;
		floor2->addParkingSpot(spot1);
	}
	for (int i = 0; i < 10; i++)
	{
		ParkingSpotI* spot1 = new CompactSpot;
		floor2->addParkingSpot(spot1);
	}
	//END : parking floor 2
	/*END : setting parkinf floors*/

	Admin admin;
	admin.addEntrancePanel(entrancePanel);
	admin.addExitPanel(exitPanel);
	admin.addParkingFloor(floor1.get());
	admin.addParkingFloor(floor2.get());

	ParkingAttendant parkingAttendance;
	ParkingLot* lot = ParkingLot::getInstance();
	/*user enters*/
	string vechileNumber1 = "KANO1604";
	VehicleType type1 = VehicleType::CAR;
	ParkingSpotType slottype1 = ParkingSpotType::COMPACT;
	ParkingTicket* ticket1 = entrancePanel->getTicket(vechileNumber1, type1);
	/*user occupied the space*/
	lot->parkVehicle(slottype1, vechileNumber1);
	lot->printBoards();
	/*user exits. freeing the parking space*/
	lot->freeVehicle(vechileNumber1);
	lot->printBoards();
	/*makes payment at the exit panel by parking attendent*/
	parkingAttendance.scanTicket(vechileNumber1);
	parkingAttendance.processTicket(vechileNumber1, PaymentMode::CashMode);
	lot->printBoards();
}