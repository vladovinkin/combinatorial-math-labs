#pragma once
#include <vector>
#include <string>

class Faces
{
public:
	Faces(const std::vector<std::vector<int>>& interior, const std::vector<int>& external);
	std::vector<std::vector<int>> GetInterior();
	const std::vector<int> GetExternal();
	std::string ToString();
	std::string VectorIntToString(const std::vector<int>& data);
private:
	std::vector<std::vector<int>> m_interior;
	std::vector<int> m_external;
	int m_size;
};