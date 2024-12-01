#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "SuperBoots.h"
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broom.h"

struct vehicleResult
{
	std::string vehicleName;
	double vehicleTime;
};

// Sorts an array of vehicleResult struct instances by vehicleTime in ascending order
void bubbleSort(vehicleResult* vRes, int size) {
	bool swapped;

	// access each array element
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		//compare two adjacent array elements and swap them if necessary
		for (int j = 0; j < size - i - 1; j++) {
			if (vRes[j].vehicleTime > vRes[j + 1].vehicleTime) {
				vehicleResult temp = vRes[j];
				vRes[j] = vRes[j + 1];
				vRes[j + 1] = temp;
				swapped = true;
			}
		}

		// If no two elements were swapped, then break
		if (!swapped)
			break;
	}
}

void printRaceStatistics(vehicleResult* vRes, int size) {
	bubbleSort(vRes, size);
	std::cout << "Результаты гонки:" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << i + 1 << ". " << vRes[i].vehicleName << ". Время: " << vRes[i].vehicleTime << std::endl;
}

void printRaceTypeList() {
	std::cout << "1. Гонка для наземного транспорта" << std::endl;
	std::cout << "2. Гонка для воздушного транспорта" << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
	std::cout << "Выберите тип гонки: ";
}

void printModeList() {
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
	std::cout << "1. Зарегистрировать транспорт" << std::endl;
	std::cout << "2. Начать гонку" << std::endl;
	std::cout << "Выберите действие: ";
}

void printVehicleList() {
	std::cout << "1. Верблюд" << std::endl;
	std::cout << "2. Верблюд быстроход" << std::endl;
	std::cout << "3. Кентавр" << std::endl;
	std::cout << "4. Ботинки-вездеходы" << std::endl;
	std::cout << "5. Ковер-самолёт" << std::endl;
	std::cout << "6. Орел" << std::endl;
	std::cout << "7. Метла" << std::endl;
	std::cout << "0. Закончить регистрацию" << std::endl;
	std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
}

int main()
{
	setlocale(LC_ALL, "russian");
	int raceType, dist, vehicleModel, mode;
	double vehicleTime;
	vehicleResult* race_result = new vehicleResult[7];

	//while (true)
	//{
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	printRaceTypeList();
	std::cin >> raceType;
	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> dist;
	Race race(raceType, dist);
	switch (race.getRaceType())
	{
	case Race::RaceType::GROUND:
		std::cout << "Гонка для наземного транспорта. ";
		break;
	case Race::RaceType::AIR:
		std::cout << "Гонка для воздушного транспорта. ";
		break;
	case Race::RaceType::MIXED:
		std::cout << "Гонка для наземного и воздушного транспорта. ";
		break;
	default:
		std::cerr << "Ошибка ввода! Введите 1-3" << std::endl;
		break;
	}
	std::cout << "Расстояние " << race.getDist() << std::endl;


	while (true) {
		if (race.getVehicleCount())
		{
			std::cout << "Зарегистрированные транспортные средства: ";
			for (int i = 0; i < race.getVehicleCount(); i++)
				std::cout << race_result[race.getVehicleCount() - 1].vehicleName;
		}
		printModeList();
		std::cin >> mode;
		if (mode == 2 && race.getVehicleCount() < 2)
			continue;
		else if (mode == 2)
			break;
		printVehicleList();
		std::cin >> vehicleModel;
		std::string vehicleName{};
		try {
			race.registerVehicle(vehicleModel, vehicleName, vehicleTime);
			std::cout << vehicleName << " успешно зарегистрирован!" << std::endl;
			race_result[race.getVehicleCount() - 1].vehicleName = vehicleName;
			race_result[race.getVehicleCount() - 1].vehicleTime = vehicleTime;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	printRaceStatistics(race_result, race.getVehicleCount());
	//}

	delete[] race_result;
}
