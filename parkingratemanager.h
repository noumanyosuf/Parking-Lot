#pragma once
#include"vehicle.h"
#include<memory.h>
class ParkingRateCalculatorI
{
public:
	virtual float getRate() = 0;
	VehicleType type;
};

class CarParkingRateCalculator : public ParkingRateCalculatorI
{
public:
	CarParkingRateCalculator() {type = VehicleType::CAR;}
	float getRate() { return 50.0; }
};

class VanParkingRateCalculator : public ParkingRateCalculatorI
{
public:
	VanParkingRateCalculator() { type = VehicleType::VAN; }
	float getRate() { return 60.0; }
};

class TruckParkingRateCalculator : public ParkingRateCalculatorI
{
public:
	TruckParkingRateCalculator() { type = VehicleType::TRUCK; }
	float getRate() { return 200.0; }
};

class MotorcycleParkingRateCalculator : public ParkingRateCalculatorI
{
public:
	MotorcycleParkingRateCalculator() { type = VehicleType::MOTORBIKE; }
	float getRate() { return 20.0; }
};

class ParkingRateManager
{
	ParkingRateManager() = delete;
	ParkingRateManager(const ParkingRateManager&) = delete;
public:
	static double getRate(VehicleType type);
};