#include "TreeCount.h"

TreeCount::TreeCount(const Matrix& srcMatrix)
{
	int size = static_cast<int>(srcMatrix.size());
	m_KirchhoffMatrix = Matrix(size, std::vector<double>(size, 0));

	for (auto i = 0; i < size; i++)
	{
		for (auto j = 0; j < size; j++)
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
