#pragma once

#include "GroundVehicle.h"

class Camel : public GroundVehicle
{
private:
	static unsigned int count;

public:
	Camel();

	double calcRaceTime(Race& r) const;

	void check_count();
};
