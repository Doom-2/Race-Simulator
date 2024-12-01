#include "AirVehicle.h"

AirVehicle::AirVehicle(const std::string& name, const int& speed)
	: Vehicle(name, speed) {}

double AirVehicle::calcRaceTime(Race& r) const {
	return r.getDist() * (1-_distReductionFactor/100.0) / _speed;
}
