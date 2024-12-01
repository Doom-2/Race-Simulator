#include "FastCamel.h"

unsigned int FastCamel::count = 0;
FastCamel::FastCamel() : GroundVehicle("Верблюд-быстроход", 40, 10) {
	check_count();
	_restTime = 5;
};

double FastCamel::calcRaceTime(Race& r) const {
	int restCounter = (r.getDist() / _speed) / _moveTime;
	if (!restCounter)
		return static_cast<double>(r.getDist() / _speed);
	else if (restCounter == 1)
		return static_cast<double>(r.getDist() / _speed) + _restTime;
	else if (restCounter == 2)
		return static_cast<double>(r.getDist() / _speed) + _restTime + (_restTime + 1.5);
	else
		return static_cast<double>(r.getDist() / _speed) + _restTime + (_restTime + 1.5) +
		(_restTime + 3) * (restCounter - 1);
}

void FastCamel::check_count() {
	if (++count > 1)
		throw std::overflow_error(_name + " уже зарегистрирован!");
}
