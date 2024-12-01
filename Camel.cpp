#include "Camel.h"

unsigned int Camel::count = 0;

Camel::Camel() : GroundVehicle("Верблюд", 10, 30) {
	check_count();
	_restTime = 5;
};

double Camel::calcRaceTime(Race& r) const {
	int restCounter = (r.getDist() / _speed) / _moveTime;
	if (!restCounter)
		return static_cast<double>(r.getDist() / _speed);
	else if (restCounter == 1)
		return static_cast<double>(r.getDist() / _speed) + _restTime;
	else
		return static_cast<double>(r.getDist() / _speed) + _restTime + (_restTime + 3) * (restCounter - 1);		
}

void Camel::check_count() {
	if (++count > 1)
		throw std::overflow_error(_name + " уже зарегистрирован!");
}
