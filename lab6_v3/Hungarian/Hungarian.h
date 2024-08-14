#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

const int INF = INT_MAX;

using Matrix = std::vector<std::vector<int>>;
using Mark = std::vector<std::vector<bool>>;

class Hungarian
{
public:
	Hungarian(const Matrix& srcMatrix);
	std::vector<int> GetAssignment();
	int GetTotalCost();
	void Algorithm();
private:
	void ReduceRows();
	void ReduceColumns();
	void CoverZeros(std::vector<bool>& coveredRows, std::vector<bool>& coveredCols);
	void UpdateMatrix(std::vector<bool>& coveredRows, std::vector<bool>& coveredCols);
	void AssignJob();
	bool CheckAssignJob(std::pair <int, int>& pos);
	void ChangeMatrix(std::pair<int, int> pos);
	void ChangeAssign(std::pair<int, int> pos);
	void FindAssignment();
	void PrintResult();
private:
	Matrix m_matrix;
	Matrix m_matrixCopy;
	std::vector<int> m_assignment;
};
