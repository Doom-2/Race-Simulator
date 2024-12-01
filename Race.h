#pragma once

#include <iostream>

class Race
{
private:
	static unsigned int vehicle_count;

public:
	enum class RaceType
	{
		GROUND = 1,
		AIR,
		MIXED
	};

	enum class VehicleModel
	{
		CAMEL = 1,
		FAST_CAMEL,
		CENTAUR,
		SUPER_BOOTS,
		MAGIC_CARPET,
		EAGLE,
		BROOM
	};

	Race(int rt, int dist);

	int getDist() const;

	void registerVehicle(size_t vehicleNumber, std::string& vehicleName, double& vehicleTime);

	int getVehicleCount();

	RaceType getRaceType() const;

protected:
	RaceType _rt;
	VehicleModel _vm;
	int _dist{};
};
