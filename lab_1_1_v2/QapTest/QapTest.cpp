#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"
#include "../Qap/Qap.h"

SCENARIO("Проверка размещения 5 предприятий")
{
	setlocale(LC_ALL, "rus");

	std::vector<std::vector<int>> C = {
		{ 0, 17, 30, 5, 3 },
		{ 0, 0, 25, 21, 21 },
		{ 0, 0, 0, 3, 4 },
		{ 0, 0, 0, 0, 13 },
		{ 0, 0, 0, 0, 0 },
	};

	std::vector<std::vector<int>> Q = {
		{ 0, 8, 11, 8, 1},
		{ 0, 0, 4, 13, 1 },
		{ 5, 2, 0, 12, 14 },
		{ 7, 12, 8, 0, 13 },
		{ 2, 12, 11, 10, 0 },
	};

	Qap qap = Qap(C, Q);

	GIVEN("Подготовленные ответы")
	{
		int rMin = 1631;
		std::vector<int> queue = {3, 1, 2, 4, 5};

		WHEN("Запуск расчёта")
		{
			qap.Run();

			THEN("Получаем оптимальные данные")
			{
				CHECK(qap.GetRMin() == rMin);
				CHECK(qap.GetQueueMin() == queue);
			}
		}
	}
}