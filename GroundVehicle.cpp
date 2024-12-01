#include "GroundVehicle.h"

GroundVehicle::GroundVehicle(const std::string& name, const int& speed, const int& moveTime)
	: Vehicle(name, speed), _moveTime(moveTime) {
}

double GroundVehicle::calcRaceTime(Race& r) const {
	int restCounter = (r.getDist() / _speed) / _moveTime;
	return static_cast<double>(r.getDist() / _speed) + _restTime * restCounter;
}
