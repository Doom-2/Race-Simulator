#pragma once

#include "GroundVehicle.h"

class SuperBoots : public GroundVehicle
{
private:
	static unsigned int count;

public:
	SuperBoots();

	double calcRaceTime(Race& r) const;

	void check_count();
};
