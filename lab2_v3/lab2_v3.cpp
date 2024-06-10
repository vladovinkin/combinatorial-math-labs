#include <iostream>
#include "LittleAlgorithm.h"

int main()
{
	std::vector<std::vector<int>> inputMatrix1 = {
		{0, 8, 1, 0, 3, 0},
		{8, 0, 6, 5, 0, 0},
		{1, 6, 0, 4, 5, 0},
		{0, 5, 4, 0, 6, 4},
		{3, 0, 5, 6 ,0, 7},
		{0, 0, 0, 4, 7, 0},
	};

	LittleAlgorithm little = LittleAlgorithm();
	little.LoadData(inputMatrix1);
	little.Run();

	return 0;
}
