#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../oop-homeworks/catch2/catch.hpp"
#include "../BagPack/BackPack.h"

SCENARIO("Проверка #1")
{
	setlocale(LC_ALL, "rus");

	GIVEN("Подготовленные ответы #1")
	{
        std::vector<Item> items = {
        {1, 2},
        
        };
        int maxWeight = 55;

		BackPack backPack = BackPack(maxWeight, items);

		WHEN("Запуск расчёта #1")
		{
			backPack.Run();

			THEN("Получаем оптимальные данные #1")
			{
				CHECK(backPack.GetBackPackBestCost() == 34);
				CHECK(backPack.GetBackPackBestWeight() == 34);
			}
		}
	}
}