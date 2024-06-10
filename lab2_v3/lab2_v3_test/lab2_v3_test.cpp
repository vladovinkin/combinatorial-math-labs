#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"
#include "../LittleAlgorithm.h"

/*
* проверял с решениями на сайте https://vinogradovad.github.io/Traveling-salesman-website/
*/

SCENARIO("Check 5-vertex graph")
{
	LittleAlgorithm little = LittleAlgorithm();
	little.setDebugModeOutput(false);

	GIVEN("5-vertex graph")
	{
		std::vector<std::vector<int>> inputMatrix = {
			{0,5,3,0,9},
			{5,0,0,4,8},
			{5,0,0,2,6},
			{0,4,2,0,7},
			{9,8,6,7,0},
		};
		little.LoadData(inputMatrix);

		WHEN("Run the algorithm")
		{
			little.Run();

			THEN("Take best result")
			{
				CHECK(little.getResultSum() == 25);
			}
		}
	}
}

SCENARIO("Check 6-vertex graph")
{
	LittleAlgorithm little = LittleAlgorithm();
	little.setDebugModeOutput(false);

	GIVEN("6-vertex graph")
	{
		std::vector<std::vector<int>> inputMatrix = {
			{0, 8, 1, 0, 3, 0},
			{8, 0, 6, 5, 0, 0},
			{1, 6, 0, 4, 5, 0},
			{0, 5, 4, 0, 6, 4},
			{3, 0, 5, 6 ,0, 7},
			{0, 0, 0, 4, 7, 0},
		};
		little.LoadData(inputMatrix);

		WHEN("Run the algorithm")
		{
			little.Run();

			THEN("Take best result")
			{
				CHECK(little.getResultSum() == 26);
			}
		}
	}
}

SCENARIO("Check 8-vertex graph")
{
	LittleAlgorithm little = LittleAlgorithm();
	little.setDebugModeOutput(false);

	GIVEN("8-vertex graph")
	{
		std::vector<std::vector<int>> inputMatrix = {
			{0, 5, 8, 10, 0, 0, 3, 6},
			{5, 0, 2, 0, 0, 0, 0, 1},
			{8, 2, 0, 4, 5, 6, 0, 7},
			{10, 0, 4, 0, 12, 9, 7, 0},
			{0, 0, 5, 12, 0, 9, 0, 12},
			{0, 0, 6, 9, 9, 0, 8, 0},
			{3, 0, 0, 7, 0, 8, 0, 2},
			{6, 1, 7, 0, 12, 0, 2, 0},
		};
		little.LoadData(inputMatrix);

		WHEN("Run the algorithm")
		{
			little.Run();

			THEN("Take best result")
			{
				CHECK(little.getResultSum() == 41);
			}
		}
	}
}

SCENARIO("Check 14-vertex graph")
{
	LittleAlgorithm little = LittleAlgorithm();
	little.setDebugModeOutput(false);

	GIVEN("14-vertex graph")
	{
		std::vector<std::vector<int>> inputMatrix = {
			{0, 69, 71, 113, 167, 107, 113, 76, 149, 29, 122, 122, 133, 189},
			{69, 0, 33, 102, 101, 39, 72, 13, 93, 68, 96, 55, 73, 136},
			{71,33,0,68,100,52,45,45,78,57,64,57,101,118},
			{113,102,68,0,128,111,48,114,89,85,23,103,164,108},
			{167,101,100,128,0,64,81,100,42,156,107,45,92,64},
			{107,39,52,11,64,0,68,35,68,103,98,22,54,110},
			{113,72,45,48,81,68,0,81,45,92,30,56,122,77},
			{76,13,45,114,100,35,81,0,97,78,107,56,61,140},
			{149,93,78,89,42,68,45,97,0,133,66,46,114,43},
			{29,68,57,85,156,103,92,78,133,0,96,113,139,169},
			{122,96,64,23,107,98,30,107,66,96,0,86,152,85},
			{122,55,57,103,45,22,56,56,46,113,86,0,70,88},
			{133,72,101,164,92,54,122,61,114,139,152,70,0,152},
			{189,136,118,108,64,110,77,140,43,169,85,88,152,0},
		};
		little.LoadData(inputMatrix);

		WHEN("Run the algorithm")
		{
			little.Run();

			THEN("Take best result")
			{
				CHECK(little.getResultSum() == 736);
			}
		}
	}
}
