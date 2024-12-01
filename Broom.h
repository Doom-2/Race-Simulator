#pragma once
#include "AirVehicle.h"

class Broom : public AirVehicle
{
private:
	static unsigned int count;

public:
	Broom();

	double calcRaceTime(Race& r) const;

	void check_count();
};
