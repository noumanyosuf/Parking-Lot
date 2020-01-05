#include "parkingratemanager.h"

double ParkingRateManager::getRate(VehicleType type)
{
	unique_ptr<ParkingRateCalculatorI> calculator;
	if (type == VehicleType::CAR)
	{
		calculator = unique_ptr<ParkingRateCalculatorI>(new CarParkingRateCalculator());
	}
	else if (type == VehicleType::MOTORBIKE)
	{
		calculator = unique_ptr<ParkingRateCalculatorI>(new MotorcycleParkingRateCalculator());
	}
	else if (type == VehicleType::TRUCK)
	{
		calculator = unique_ptr<ParkingRateCalculatorI>(new TruckParkingRateCalculator());
	}
	else if (type == VehicleType::VAN)
	{
		calculator = unique_ptr<ParkingRateCalculatorI>(new VanParkingRateCalculator());
	}
	return calculator->getRate();
}
