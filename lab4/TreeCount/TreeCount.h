#pragma once
#include <vector>

using Matrix = std::vector<std::vector<double>>;

class TreeCount
{
public:
	TreeCount(const Matrix& srcMatrix);
	Matrix GetKirchhoffMatrix();
	int GetCountTree();
private:
	Matrix GetMinor();
	int GetDeterminant(Matrix &matrix);
private:	
	Matrix m_KirchhoffMatrix;
	int m_size;
};

