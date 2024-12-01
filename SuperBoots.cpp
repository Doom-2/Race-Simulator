#include "SuperBoots.h"

unsigned int SuperBoots::count = 0;

SuperBoots::SuperBoots() : GroundVehicle("Ботинки-вездеходы", 6, 60) {
	check_count();
	_restTime = 10;
};

double SuperBoots::calcRaceTime(Race& r) const {
	int restCounter = (r.getDist() / _speed) / _moveTime;
	if (!restCounter)
		return static_cast<double>(r.getDist() / _speed);
	else if (restCounter == 1)
		return static_cast<double>(r.getDist() / _speed) + _restTime;
	else
		return static_cast<double>(r.getDist() / _speed) + _restTime + (_restTime - 5) * (restCounter - 1);

}

void SuperBoots::check_count() {
	if (++count > 1)
		throw std::overflow_error(_name + " уже зарегистрированы!");
}
