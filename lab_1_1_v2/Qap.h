#pragma once
#include "stdafx.h"

class Qap
{
public:
	Qap(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&);
	void Run();
	void showMatrixC() const;
	void showMatrixQ() const;
	void setDebugModeOutput(bool);
private:	
	void showMatrix(const std::vector<std::vector<int>>&) const;
	void CopyVector(const std::vector<int>& in, std::vector<int>& out);
	bool CalculateVariant();
	void Init();
	std::vector<std::vector<int>> m_data_c;
	std::vector<std::vector<int>> m_data_q;

	// текущий вариант
	std::vector<int> m_queueP;

	// вариант с минимумом затрат
	std::vector<int> m_queuePmin;

	int m_rMin;
	bool m_debugModeOutput;
};
