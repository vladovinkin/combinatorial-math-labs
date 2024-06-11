#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"

SCENARIO("Проверка...")
{
	setlocale(LC_ALL, "rus");

	GIVEN("Подготовленные ответы")
	{

		WHEN("Запуск расчёта")
		{

			THEN("Получаем оптимальные данные")
			{
				CHECK(true);
			}
		}
	}
}