#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"

SCENARIO("��������...")
{
	setlocale(LC_ALL, "rus");

	GIVEN("�������������� ������")
	{

		WHEN("������ �������")
		{

			THEN("�������� ����������� ������")
			{
				CHECK(true);
			}
		}
	}
}