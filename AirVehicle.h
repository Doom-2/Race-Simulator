#pragma once

#include "Vehicle.h"

class AirVehicle : public Vehicle
{
protected:
	int _distReductionFactor{};

public:
	AirVehicle(const std::string& name, const int& speed);

	double calcRaceTime(Race& r) const;
};
