#include "Graph.h"

Graph::Graph(const std::vector<std::vector<int>>& m)
{
	m_matrix = m;
	m_size = static_cast<int>(m.size());
}

Graph::Graph(int size)
{
	m_size = size;
	m_matrix = std::vector(m_size, std::vector<int>(m_size, 0));
}

std::string Graph::ToString()
{
	std::string res = "";
	for (auto i = 0; i < m_size; i++)
	{
		for (auto j = 0; j < m_size; j++)
		{
			if (m_matrix[i][j] == 1)
			{

				res += std::to_string(i) + "<---->" + std::to_string(j) + "\n";
			}
		}
	}
	return res;
}

void Graph::AddEdge(int k, int m)
{
	m_matrix[k][m] = m_matrix[m][k] = 1;
}

bool Graph::ContainsEdge(int k, int m)
{
	return m_matrix[k][m] == 1;
}

std::vector<int> Graph::GetCycle()
{
	std::vector<int> cycle;
	std::vector<int> used(m_size, 0);
	bool hasCycle = DfsCycle(cycle, used, -1, 0);
	if (!hasCycle)
	{
		cycle.clear();
		return cycle;
	}
	std::vector<int> result;
	for (int v : cycle)
	{
		result.push_back(v);
	}
	return result;
}

// Поиск простого цикла, используя DFS алгоритм
bool Graph::DfsCycle(std::vector<int>& result, std::vector<int>& used, int parent, int v)
{
	used[v] = 1;
	for (int i = 0; i < m_size; i++)
	{
		if (i == parent || m_matrix[v][i] == 0)
		{
			continue;
		}
		if (used[i] == 0)
		{
			result.push_back(v);
			if (DfsCycle(result, used, v, i))
			{
				// Цикла найден
				return true;
			}
			else
			{
				result.pop_back();
			}
		}
		if (used[i] == 1)
		{
			result.push_back(v);
			//Найден цикл
			std::vector<int> cycle{};
			//"Выдергиваем" вершины цикла из порядка обхода
			for (auto j = 0; j < result.size(); j++)
			{
				if (result.at(j) == i)
				{
					for (auto k = j; k < result.size(); k++)
					{
						cycle.push_back(result.at(k));
					}
					result.clear();
					result = cycle;
					return true;
				}
			}
			return true;
		}
	}
	used[v] = 2;
	return false;
}

//Поиск связных компонент графа G - G', дополненного ребрами из G,
// один из концов которых принадлежит связной компоненте, а другой G'
void Graph::DfsSegments(std::vector<int> used, std::vector<bool> laidVertexes, Graph result, int v)
{
	used[v] = 1;
	for (int i = 0; i < m_size; i++)
	{
		if (m_matrix[v][i] == 1)
		{
			result.AddEdge(v, i);
			if (used[i] == 0 && !laidVertexes[i])
			{
				DfsSegments(used, laidVertexes, result, i);
			}
		}
	}
}

std::vector<Graph> Graph::GetSegments(std::vector<bool> laidVertexes, std::vector<std::vector<bool>> edges)
{
	std::vector<Graph> segments{};
	for (auto i = 0; i < m_size; i++)
	{
		for (auto j = i + 1; j < m_size; j++)
		{
			if (m_matrix[i][j] == 1 && !edges[i][j] && laidVertexes[i] && laidVertexes[j])
			{
				Graph t = Graph(m_size);
				t.AddEdge(i, j);
				segments.push_back(t);
			}
		}
	}
	// Поиск связных компонент графа G - G', дополненного ребрами из G,
    // один из концов которых принадлежит связной компоненте, а другой G'
	std::vector<int> used(m_size, 0);
	for (auto i = 0; i < m_size; i++)
	{
		if (used[i] == 0 && !laidVertexes[i])
		{
			Graph res = Graph(m_size);
			DfsSegments(used, laidVertexes, res, i);
			segments.push_back(res);
		}
	}
	return segments;
}

//Поиск цепи в выбранном сегменте, используя DFS алгоритм
void Graph::DfsChain(std::vector<int> used, std::vector<bool> laidVertexes, std::vector<int> chain, int v)
{
	used[v] = 1;
	chain.push_back(v);
	for (auto i = 0; i < m_size; i++)
	{
		if (m_matrix[v][i] == 1 && used[i] == 0)
		{
			if (!laidVertexes[i])
			{
				DfsChain(used, laidVertexes, chain, i);
			}
			else
			{
				chain.push_back(i);
			}
			return;
		}
	}
}

std::vector<int> Graph::GetChain(std::vector<bool> laidVertexes)
{
	std::vector<int> result{};
	for (auto i = 0; i < m_size; i++)
	{
		if (laidVertexes[i])
		{
			bool inGraph = false;
			for (auto j = 0; j < m_size; j++)
			{
				if (ContainsEdge(i, j))
				{
					inGraph = true;
				}
			}
			if (inGraph)
			{
				std::vector<int> used(m_size, 0);
				DfsChain(used, laidVertexes, result, i);
				break;
			}
		}
	}
	return result;
}

void Graph::LayChain(std::vector<std::vector<bool>> result, std::vector<int> chain, bool cyclic)
{
	for (auto i = 0; i < chain.size() - 1; i++)
	{
		result[chain[i + 1]][chain[i]] = result[chain[i]][chain[i + 1]] = true;
	}
	if (cyclic)
	{
		result[chain.size() - 1][0] = result[0][chain.size() - 1] = true;
	}
}

bool Graph::VectorIntContains(std::vector<int>& values, int target)
{
	int cnt = static_cast<int>(count(values.begin(), values.end(), target));
	return cnt > 0;
}

//Проверка на то, что данный сегмент содержится в данной грани
bool Graph::IsFaceContainsSegment(std::vector<int> face, Graph segment, std::vector<bool> laidVertexes)
{
	for (auto i = 0; i < m_size; i++)
	{
		for (auto j = 0; j < m_size; j++)
		{
			if (segment.ContainsEdge(i, j))
			{
				if ((laidVertexes[i] && !VectorIntContains(face, i)) || (laidVertexes[j] && !VectorIntContains(face, j)))
				{
					return false;
				}
			}
		}
	}
	return true;
}

std::vector<int> Graph::CalcNumOfFacesContainedSegments(std::vector<std::vector<int>> intFaces, std::vector<int> extFace, std::vector<Graph> segments, std::vector<bool> laidVertexes, std::vector<std::vector<int>> destFaces)
{
	std::vector<int> count(segments.size(), 0);
	for (auto i = 0; i < segments.size(); i++)
	{
		for (auto face : intFaces)
		{
			if (IsFaceContainsSegment(face, segments[i], laidVertexes))
			{
				destFaces[i] = face;
				count[i]++;
			}
		}
		if (IsFaceContainsSegment(extFace, segments[i], laidVertexes))
		{
			destFaces[i] = extFace;
			count[i]++;
		}
	}
	return count;
}

// Получить плоскую укладку графа
// Возвращаются все грани уложенного планарного графа
// Если это невозможно(граф не планарный), то null
Faces Graph::GetPlanarLaying()
{
	//Если граф одновершинный, то возвращаем две грани
	if (m_size == 1)
	{
		std::vector<std::vector<int>> faces{};
		std::vector<int> outerFace{};
		outerFace.push_back(0);
		faces.push_back(outerFace);
		faces.push_back(outerFace);
		return Faces(faces, outerFace);
	}

	// Ищем цикл, если его нет, до граф не соответствует условиям алгоритма
	// (Нет циклов => дерево => планарный)
	std::vector c = GetCycle();
	if (c.empty())
	{
		return Faces({}, {});
	}

	// Списки граней
	std::vector<std::vector<int>> intFaces{};
	std::vector<int> extFace = c;
	intFaces.push_back(c);
	intFaces.push_back(extFace);

	// Массивы уже уложенных вершин и ребер соответственно
	std::vector<bool> laidVertexes(m_size, false);
	std::vector<std::vector<bool>> laidEdges(m_size, std::vector<bool>(m_size, false));
	for (auto i : c)
	{
		laidVertexes[i] = true;
	}

	// Укладываем найденный цикл
	LayChain(laidEdges, c, true);

	//Второй шаг алгоритма:
	//выделение множества сегментов, подсчет числа вмещающих граней,
	//выделение цепей из сегментов, укладка цепей, добавление новых граней
	while (true)
	{
		std::vector<Graph> segments = GetSegments(laidVertexes, laidEdges);
		// Если нет сегментов, го граф - найденный постой цикл => планарный
		if (segments.size() == 0)
		{
			break;
		}
		// Массив граней, в которые будут уложены соответствующие сегменты с минимальным числом calcNumOfFacesContainedSegments()
		std::vector<std::vector<int>> destFaces(segments.size(), std::vector<int>(segments.size(), 0));
		std::vector<int> count = CalcNumOfFacesContainedSegments(intFaces, extFace, segments, laidVertexes, destFaces);

		// Ищем минимальное число calcNumOfFacesContainedSegments()
		int mi = 0;
		for (auto i = 0; i < segments.size(); i++)
		{
			if (count[i] < count[mi])
			{
				mi = i;
			}
		}

		// Если хотя бы одно ноль, то граф не планарный
		if (count[mi] == 0)
		{
			return Faces({}, {});
		}
		else
		{
			// Укладка выбранного сегмента
			// Выделяем цепь между двумя контактными вершинами
			std::vector<int> chain = segments[mi].GetChain(laidVertexes);
			// Помечаем вершины цепи как уложенные
			for (auto i : chain)
			{
				laidVertexes[i] = true;
			}
			// Укладываем соответствующие ребра цепи
			LayChain(laidEdges, chain, false);

			// Целевая грань, куда будет уложен выбранный сегмент
			std::vector<int> face = destFaces[mi];
			// Новые грани, порожденные разбиением грани face выбранным сегментом
			std::vector<int> face1{};
			std::vector<int> face2{};
			// Ищем номера контактных вершин цепи
			int contactFirst = 0, contactSecond = 0;
			for (int i = 0; i < face.size(); i++)
			{
				if (face[i] == chain[0])
				{
					contactFirst = i;
				}
				if (face[i] == chain[chain.size() - 1])
				{
					contactSecond = i;
				}
			}
			// Находим обратную цепь (цепь, пробегаемая в обратном направлении)
			std::vector<int> reverseChain = chain;
			std::reverse(reverseChain.begin(), reverseChain.end());
			int faceSize = static_cast<int>(face.size());
			if (face != extFace) // Если целевая грань не внешняя
			{
				// Укладываем прямую цепь в одну из порожденных граней,
				// а обратную в другую в зависимости от номеров контактных вершин
				if (contactFirst < contactSecond)
				{
					face1.insert(face1.end(), chain.begin(), chain.end());
					for (auto i = (contactSecond + 1) % faceSize; i != contactFirst; i = (i + 1) % faceSize)
					{
						face1.push_back(face[i]);
					}
					face2.insert(face2.end(), reverseChain.begin(), reverseChain.end());
					for (auto i = (contactFirst + 1) % faceSize; i != contactSecond; i = (i + 1) % faceSize)
					{
						face2.push_back(face[i]);
					}
				}
				else
				{
					face1.insert(face1.end(), reverseChain.begin(), reverseChain.end());
					for (auto i = (contactFirst + 1) % faceSize; i != contactSecond; i = (i + 1) % faceSize)
					{
						face1.push_back(face[i]);
					}
					face2.insert(face2.end(), chain.begin(), chain.end());
					for (auto i = (contactSecond + 1) % faceSize; i != contactFirst; i = (i + 1) % faceSize)
					{
						face2.push_back(face[i]);
					}
				}
				// Удаляем целевую грань(она разбилась на две новые)
				// Добавляем порожденные грани в множество внутренних граней
				auto fc = std::find(intFaces.begin(), intFaces.end(), face);
				if (fc != intFaces.end())
				{
					intFaces.erase(fc);
				}

				intFaces.push_back(face1);
				intFaces.push_back(face2);
			}
			else
			{
				// Если целевая грань совпала с внешней
				// Все то же самое, только одна из порожденных граней - новая внешняя грань
				std::vector<int> newOuterFace{};
				if (contactFirst < contactSecond)
				{
					newOuterFace.insert(newOuterFace.end(), chain.begin(), chain.end());
					for (auto i = (contactSecond + 1) % faceSize; i != contactFirst; i = (i + 1) % faceSize)
					{
						newOuterFace.push_back(face[i]);

					}
					face2.insert(face2.end(), chain.begin(), chain.end());
					for (auto i = (contactSecond - 1 + faceSize) % faceSize; i != contactFirst; i = (i - 1 + faceSize) % faceSize)
					{
						face2.push_back(face[i]);
					}
				}
				else
				{
					newOuterFace.insert(newOuterFace.end(), reverseChain.begin(), reverseChain.end());
					for (auto i = (contactFirst + 1) % faceSize; i != contactSecond; i = (i + 1) % faceSize)
					{
						newOuterFace.push_back(face[i]);
					}
					face2.insert(face2.end(), reverseChain.begin(), reverseChain.end());
					for (auto i = (contactFirst - 1 + faceSize) % faceSize; i != contactSecond; i = (i - 1 + faceSize) % faceSize)
					{
						face2.push_back(face[i]);
					}
				}
				// Удаляем старые, добавляем новые
				auto fc = std::find(intFaces.begin(), intFaces.end(), extFace);
				if (fc != intFaces.end())
				{
					intFaces.erase(fc);
				}
				intFaces.push_back(newOuterFace);
				intFaces.push_back(face2);
				extFace = newOuterFace;
			}
		}
	}
	return Faces(intFaces, extFace);
}
