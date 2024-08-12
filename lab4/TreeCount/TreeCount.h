#pragma once
#include <vector>

using Matrix = std::vector<std::vector<double>>;

class TreeCount
{
public:
	TreeCount(const Matrix& srcMatrix);
	Matrix GetKirchhoffMatrix();
private:
	Matrix GetMinor();
	Matrix m_KirchhoffMatrix;
	int m_size;
};

