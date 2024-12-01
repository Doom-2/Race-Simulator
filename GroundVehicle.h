#pragma once

#include "Vehicle.h"

class GroundVehicle : public Vehicle
{
protected:
	int _moveTime{};
	int _restTime{};

public:
	GroundVehicle(const std::string& name, const int& speed, const int& moveTime);

	double calcRaceTime(Race& r) const;
};
