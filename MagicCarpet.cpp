#include "MagicCarpet.h"

unsigned int MagicCarpet::count = 0;

MagicCarpet::MagicCarpet() : AirVehicle("Ковер-самолёт", 10) {
	check_count();
}

double MagicCarpet::calcRaceTime(Race& r) const {
	if (r.getDist() < 1000)
		return r.getDist() * (1 - _distReductionFactor / 100.0) / _speed;
	else if (r.getDist() < 5000)
		return r.getDist() * (1 - (_distReductionFactor + 3)/ 100.0) / _speed;
	else if (r.getDist() < 10000)
		return r.getDist() * (1 - (_distReductionFactor + 10) / 100.0) / _speed;
	else
		return r.getDist() * (1 - (_distReductionFactor + 5) / 100.0) / _speed;
}

void MagicCarpet::check_count() {
	if (++count > 1)
		throw std::overflow_error(_name + " уже зарегистрирован!");
}
