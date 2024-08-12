#include "TreeCount.h"

TreeCount::TreeCount(const Matrix& srcMatrix)
{
	m_size = static_cast<int>(srcMatrix.size());
	m_KirchhoffMatrix = Matrix(m_size, std::vector<double>(m_size, 0));

	for (auto i = 0; i < m_size; i++)
	{
		for (auto j = 0; j < m_size; j++)
		{
			if (srcMatrix[i][j] > DBL_EPSILON)
			{
				m_KirchhoffMatrix[i][j] = -srcMatrix[i][j];
				m_KirchhoffMatrix[i][i] += srcMatrix[i][j];
			}
		}
	}
}

Matrix TreeCount::GetKirchhoffMatrix()
{
	return m_KirchhoffMatrix;
}

Matrix TreeCount::GetMinor()
{
	Matrix minor(m_size - 1, std::vector<double>(m_size - 1));
	for (auto i = 1; i < m_size; i++)
	{
		for (auto j = 1; j < m_size; j++)
		{
			minor[i - 1][j - 1] = m_KirchhoffMatrix[i][j];
		}
	}
	return minor;
}

int TreeCount::GetDeterminant(Matrix& matrix)
{
	int size = static_cast<int>(matrix.size());
	double det = 1.0;

	for (int i = 0; i < size; i++)
	{
		int maxRowElem = i;
		for (int k = i + 1; k < size; k++)
		{
			if (std::abs(matrix[k][i]) > std::abs(matrix[maxRowElem][i]))
			{
				maxRowElem = k;
			}
		}
		if (matrix[maxRowElem][i] < DBL_EPSILON)
		{
			return 0;
		}
		if (i != maxRowElem)
		{
			std::swap(matrix[maxRowElem], matrix[i]);
			det = -det;
		}
		det *= matrix[i][i];
		for (int k = i + 1; k < size; k++)
		{
			double fact = matrix[k][i] / matrix[i][i];
			for (int j = i; j < size; j++)
			{
				matrix[k][j] -= fact * matrix[i][j];
			}
		}
	}
	return static_cast<int>(det);
}

int TreeCount::GetCountTree()
{
	Matrix minor = GetMinor();
	return std::abs(GetDeterminant(minor));
}
