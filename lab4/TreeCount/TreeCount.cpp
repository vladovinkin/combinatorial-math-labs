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

