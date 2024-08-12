#pragma once
#include <vector>

using Matrix = std::vector<std::vector<double>>;

class TreeCount
{
public:
	TreeCount(const Matrix& srcMatrix);
	Matrix GetKirchhoffMatrix();
private:
	Matrix m_KirchhoffMatrix;
};

