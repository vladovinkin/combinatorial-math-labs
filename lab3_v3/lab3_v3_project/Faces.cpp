#include "Faces.h"

Faces::Faces(const std::vector<std::vector<int>>& interior, const std::vector<int>& external)
{
	m_size = 0;
	if (!interior.empty() && !external.empty())
	{
		m_interior = interior;
		m_external = external;
		m_size = static_cast<int>(m_interior.size()) + m_size + static_cast<int>(m_external.size());
	}
}

std::vector<std::vector<int>> Faces::GetInterior()
{
	return m_interior;
}

const std::vector<int> Faces::GetExternal()
{
	return m_external;
}

std::string Faces::ToString()
{
	std::string result = "Faces size = " + std::to_string(m_size) + "\nExternal face:\n" + VectorIntToString(m_external) + "\nInterior faces:\n";
	for (auto f : m_interior)
	{
		result += VectorIntToString(f) + "\n";
	}
	return result;
}

std::string Faces::VectorIntToString(const std::vector<int>& data)
{
	std::string result = "[";
	for (int i = 0; i < data.size(); i++)
	{
		result += std::to_string(data[i]);
		if (i < data.size() - 1)
		{
			result += ", ";
		}

	}
	return result + "]";
}

int Faces::GetSize()const
{
	return static_cast<int>(m_size);
}

void Faces::ReverseVector(std::vector<int>& data)
{
	std::vector<int> temp{};
	while (data.size() > 0)
	{
		temp.push_back(data[data.size() - 1]);
		data.pop_back();
	}
	data = temp;
}

bool Faces::IsEqualFaces(const std::vector<int>& face1, const std::vector<int>& face2)
{
	if (face1 == face2)
	{
		return true;
	}

	std::vector<int> temp = face2;
	if (face1.size() == temp.size())
	{
		for (auto i = 1; i < face1.size(); i++)
		{
			auto iter = temp.begin();
			temp.insert(iter, temp[temp.size() - 1]);
			temp.pop_back();
			if (temp == face1)
			{
				return true;
			}
		}

		ReverseVector(temp);

		if (face1 == temp)
		{
			return true;
		}

		for (auto i = 1; i < face1.size(); i++)
		{
			auto iter = temp.begin();
			temp.insert(iter, temp[temp.size() - 1]);
			temp.pop_back();
			if (temp == face1)
			{
				return true;
			}
		}
	}

	return false;
}

