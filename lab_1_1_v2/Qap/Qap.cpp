#include "Qap.h"
#include <iostream>

Qap::Qap(const std::vector<std::vector<int>>& DataC, const std::vector<std::vector<int>>& DataQ)
{
	m_data_c = DataC;
	m_data_q = DataQ;
	Init();
}

void Qap::Run()
{
	do
	{
		if (CalculateVariant() && m_debugModeOutput)
		{
			std::cout << "R = " << m_rMin << "; vector: ";
			copy(m_queueP.begin(), m_queueP.end(), std::ostream_iterator<size_t>(std::cout, " "));
			std::cout << "\n";
		}
	} while (std::next_permutation(m_queueP.begin(), m_queueP.end()));
}

void Qap::Init()
{
	for (int i = 0; i < m_data_c.size(); i++)
	{
		m_queueP.push_back(i + 1);
		m_queuePmin.push_back(i + 1);
	}
	m_rMin = -1;
	setDebugModeOutput(false);
}

void Qap::setDebugModeOutput(bool isDebug)
{
	m_debugModeOutput = isDebug;
}

void Qap::showMatrix(const std::vector<std::vector<int>>& matrix) const
{
	std::cout << "\n\t";
	for (int i = 0; i < matrix.size(); i++)
	{
		std::cout << i + 1 << "\t";
	}
	std::cout << "\n     ";
	for (int i = 0; i < matrix.size(); i++)
	{
		std::cout << "________";
	}
	std::cout << "\n\n";
	for (int i = 0; i < matrix.size(); i++)
	{
		std::cout << i + 1 << " | " << "\t";
		for (int j = 0; j < matrix.size(); j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

void Qap::showMatrixC() const
{
	showMatrix(m_data_c);
}

void Qap::showMatrixQ() const
{
	showMatrix(m_data_q);
}

void Qap::CopyVector(const std::vector<int>& in, std::vector<int>& out)
{
	out.clear();
	for (int i = 0; i < in.size(); i++)
	{
		out.push_back(in[i]);
	}
}

bool Qap::CalculateVariant()
{
	int r = 0;
	for (auto i = 0; i < m_data_c.size(); i++)
	{
		for (auto j = i + 1; j < m_data_c.size(); j++)
		{
			r += m_data_c[i][j] * (m_data_q[m_queueP[i] - 1][m_queueP[j] - 1] + m_data_q[m_queueP[j] - 1][m_queueP[i] - 1]);
			if (m_rMin != -1 && r > m_rMin)
			{
				return false;
			}
		}
	}
	if (r < m_rMin || m_rMin == -1)
	{
		CopyVector(m_queueP, m_queuePmin);
		m_rMin = r;
		return true;
	}
	return false;
}

int Qap::GetRMin() const
{
	return m_rMin;
}

std::vector<int> Qap::GetQueueMin() const
{
	return m_queuePmin;
}
