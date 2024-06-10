#pragma once
#include <fstream>
#include <vector>

class LittleAlgorithm
{
public:
	LittleAlgorithm();
	bool LoadData(std::vector<std::vector<int>>);
	virtual void Run();
private:
	enum check{Row, Col};
	int getMin(std::vector<std::vector<int>>, int, check);
	void matrixProcedure(std::vector<std::vector<int>>);
	void showMatrix(std::vector<std::vector<int>>);
	int getResultSum();
	virtual bool validateData();
	std::vector<std::pair<int, int>> result;
	std::vector<std::vector<int>> data;
};
