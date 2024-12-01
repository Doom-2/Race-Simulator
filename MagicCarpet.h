#pragma once
#include "AirVehicle.h"

class MagicCarpet : public AirVehicle
{
private:
	static unsigned int count;

public:
	MagicCarpet();

	double calcRaceTime(Race& r) const;

	void check_count();
};
