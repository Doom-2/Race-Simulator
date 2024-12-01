#include "Broom.h"

unsigned int Broom::count = 0;

Broom::Broom() : AirVehicle("Метла", 20) {
	check_count();
}

double Broom::calcRaceTime(Race& r) const {
	return r.getDist() * (1 - (r.getDist() / 1000) / 100.0) / _speed;
}

void Broom::check_count() {
	if (++count > 1)
		throw std::overflow_error(_name + " уже зарегистрирована!");
}
