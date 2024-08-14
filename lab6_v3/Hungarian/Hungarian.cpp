#include "Hungarian.h"

Hungarian::Hungarian(const Matrix& srcMatrix)
{
	m_matrix = srcMatrix;
	m_matrixCopy = srcMatrix;
}

void Hungarian::ReduceRows()
{
	for (auto& row : m_matrix)
	{
		auto minElement = *std::min_element(row.begin(), row.end());
		if (minElement != INF)
		{
			std::transform(row.begin(), row.end(), row.begin(),
				[minElement](int element) {
					return (element != INF) ? element - minElement : INF;
				});
		}
	}
}

void Hungarian::ReduceColumns()
{
	for (auto j = 0; j < m_matrix[0].size(); j++)
	{
		int minElement = INF;
		for (auto i = 0; i < m_matrix.size(); i++)
		{
			if (m_matrix[i][j] < minElement)
			{
				minElement = m_matrix[i][j];
			}
		}
		if (minElement != INF)
		{
			for (auto i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[i][j] != INF)
				{
					m_matrix[i][j] -= minElement;
				}
			}
		}
	}
}

void Hungarian::CoverZeros(std::vector<bool>& coveredRows, std::vector<bool>& coveredCols)
{
	Mark marked(m_matrix.size(), std::vector<bool>(m_matrix.size(), false));
	for (auto i = 0; i < m_matrix.size(); i++)
	{
		for (auto j = 0; j < m_matrix.size(); j++)
		{
			if (m_matrix[i][j] == 0 && !coveredRows[i] && !coveredCols[j])
			{
				coveredCols[j] = coveredRows[i] = marked[i][j] = true;
			}
		}
	}
	std::fill(coveredRows.begin(), coveredRows.end(), false);
	std::fill(coveredCols.begin(), coveredCols.end(), false);
	for (auto i = 0; i < m_matrix.size(); i++)
	{
		for (auto j = 0; j < m_matrix.size(); j++)
		{
			if (marked[i][j])
			{
				coveredCols[j] = true;
			}
		}
	}
}

void Hungarian::UpdateMatrix(std::vector<bool>& coveredRows, std::vector<bool>& coveredCols)
{
	int minUncovered = INF;
	for (auto i = 0; i < m_matrix.size(); i++)
	{
		if (!coveredRows[i])
		{
			for (auto j = 0; j < m_matrix[i].size(); j++)
			{
				if (!coveredCols[j])
				{
					minUncovered = std::min(minUncovered, m_matrix[i][j]);
				}
			}
		}
	}
	for (auto i = 0; i < m_matrix.size(); i++)
	{
		for (auto j = 0; j < m_matrix[i].size(); j++)
		{
			if (!coveredRows[i] && !coveredCols[j])
			{
				m_matrix[i][j] -= minUncovered;
			}
			else if (coveredRows[i] && coveredCols[j])
			{
				m_matrix[i][j] += minUncovered;
			}
		}
	}
}

void Hungarian::AssignJob()
{
	for (auto i = 0; i < m_matrix.size(); i++)
	{
		for (auto j = 0; j < m_matrix[i].size(); j++)
		{
			if (m_matrix[i][j] == 0)
			{
				m_assignment.push_back(j);
				break;
			}
		}
	}
}

bool Hungarian::CheckAssignJob(std::pair <int, int>& pos)
{
	for (auto i = 0; i < m_assignment.size(); i++)
	{
		for (auto j = i + 1; j < m_assignment.size(); j++)
		{
			if (m_assignment[i] == m_assignment[j])
			{
				pos = std::make_pair(i, m_assignment[i]);
				return true;
			}
		}
	}
	return false;
}

void Hungarian::ChangeMatrix(std::pair<int, int> pos)
{
	int row = pos.first;
	if (row >= m_matrix.size())
	{
		return;
	}

	int col = pos.second;
	auto& matrixRow = m_matrix[row];
	int minElement = INF;
	for (auto j = 0; j < matrixRow.size(); j++)
	{
		if (j != col && matrixRow[j] != INF)
		{
			minElement = std::min(minElement, matrixRow[j]);
		}
	}
	if (minElement == INF)
	{
		return;
	}
	for (int& element : matrixRow)
	{
		if (element != INF)
		{
			element -= minElement;
		}
	}
}

void Hungarian::ChangeAssign(std::pair<int, int> pos)
{
	m_assignment.clear();
	for (auto i = 0; i < m_matrix.size(); i++)
	{
		for (auto j = 0; j < m_matrix[i].size(); j++)
		{
			if (m_matrix[i][j] == 0)
			{
				m_assignment.push_back(j);
				break;
			}
		}
	}
}

void Hungarian::FindAssignment()
{
	ReduceRows();
	ReduceColumns();

	std::vector<bool> coveredRows(m_matrix.size(), false);
	std::vector<bool> coveredCols(m_matrix.size(), false);
	while (true)
	{
		CoverZeros(coveredRows, coveredCols);
		if (coveredCols.size() == m_matrix.size())
		{
			break;
		}
		UpdateMatrix(coveredRows, coveredCols);
	}

	AssignJob();
	std::pair <int, int> position;
	if (CheckAssignJob(position))
	{
		ChangeMatrix(position);
		ChangeAssign(position);
	}
}

int Hungarian::GetTotalCost()
{
	int totalCost = 0;
	for (auto i = 0; i < m_assignment.size(); i++)
	{
		totalCost += m_matrixCopy[i][m_assignment[i]];
	}
	return totalCost;
}

void Hungarian::PrintResult()
{
	for (auto i = 0; i < m_assignment.size(); i++)
	{
		std::cout << "Worker " << i + 1 << " assigned to job " << m_assignment[i] + 1 << " with cost "
			<< m_matrixCopy[i][m_assignment[i]] << "\n";
	}
	std::cout << "Total cost: " << GetTotalCost() << "\n";
}

std::vector<int> Hungarian::GetAssignment()
{
	return m_assignment;
}

void Hungarian::Algorithm()
{
	FindAssignment();
}
