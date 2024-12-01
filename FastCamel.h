#pragma once

#include "GroundVehicle.h"

class FastCamel : public GroundVehicle
{
private:
	static unsigned int count;

public:
	FastCamel();

	double calcRaceTime(Race& r) const;

	void check_count();
};
