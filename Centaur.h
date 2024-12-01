#pragma once

#include "GroundVehicle.h"

class Centaur : public GroundVehicle
{
private:
	static unsigned int count;

public:
	Centaur();

	void check_count();
};
