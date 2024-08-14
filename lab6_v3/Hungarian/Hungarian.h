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
	void Algorithm();
private:
	void ReduceRows();
	void ReduceColumns();
	void CoverZeros(std::vector<bool>& coveredRows, std::vector<bool>& coveredCols);
	void UpdateMatrix(std::vector<bool>& coveredRows, std::vector<bool>& coveredCols);
	void AssignJob(std::vector<int>& assignment);
	bool CheckAssignJob(const std::vector<int>& assignment, std::pair <int, int>& pos);
	void ChangeMatrix(std::pair<int, int> pos);
	void ChangeAssign(std::vector<int>& assignment, std::pair<int, int> pos);
	void FindAssignment(std::vector<int>& assignment);
	void PrintResult(const std::vector<int> &assignment);
private:
	Matrix m_matrix;
	Matrix m_matrix_copy;
};
