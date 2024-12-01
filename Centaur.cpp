#include "Centaur.h"

unsigned int Centaur::count = 0;

Centaur::Centaur() : GroundVehicle("Кентавр", 15, 8) {
	check_count();
	_restTime = 2;
};

void Centaur::check_count() {
	if (++count > 1)
		throw std::overflow_error(_name + " уже зарегистрирован!");
}
