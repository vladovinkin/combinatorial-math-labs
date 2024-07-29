#pragma once
#include <vector>
#include <string>
#include "Faces.h"

class Graph
{
public:
	Graph(const std::vector<std::vector<int>>& m);
	Graph(int size);
	std::string ToString();
	void AddEdge(int k, int m);
	bool ContainsEdge(int k, int m);
	std::vector<int> GetCycle();
	void LayChain(std::vector<std::vector<bool>>, std::vector<int> chain, bool cyclic);
	Faces getPlanarLaying();

private:
	bool DfsCycle(std::vector<int>& result, std::vector<int>& used, int parent, int v);
	void DfsSegments(std::vector<int> used, std::vector<bool> laidVertexes, Graph result, int v);
	std::vector<Graph> GetSegments(std::vector<bool> laidVertexes, std::vector<std::vector<bool>> edges);
	void DfsChain(std::vector<int> used, std::vector<bool> lsidVertexes, std::vector<int> chain, int v);
	std::vector<int> GetChain(std::vector<bool> laidVertexes);
	bool IsFaceContainsSegment(std::vector<int> face, Graph segment, std::vector<bool> laidVertexes);
	std::vector<int> CalcNumOfFacesContainedSegments(std::vector<std::vector<int>> intFaces, std::vector<int> extFace, std::vector<Graph> segments, std::vector<bool> laidVertexes, std::vector<std::vector<int>> destFaces);
	
private:
	std::vector<std::vector<int>> m_matrix;
	int m_size;
};

