/*
Алгоритм поднять-в-начало:
	- занести все v э V : {s, t} в односвязный список
	- пройти по списку и выполнить DISCHARGE от каждой вершины
		- при этом, если в результате DISCHARGE(v) R(v) увеличилось, 
			то поместить v в начало списка и начать заново
		- если дошли до конца, то завершить работу

*/
#include <iostream>
#include "MaxFlowFinder.h"
#include <vector>

int main()
{
    size_t numberOfVertices = 11;
    size_t numberOfEdges = 18;
    VertexNumber start = 0;
    VertexNumber finish = 10;

    std::vector < std::vector<int>> edges{
        { 0, 3, 25 },
        { 0, 5, 45 },
        { 0, 8, 30 },
        { 3, 1, 15 },
        { 3, 4, 35 },
        { 5, 3, 10 },
        { 5, 4, 20 },
        { 5, 6, 15 },
        { 8, 6, 35 },
        { 8, 9, 45 },
        { 1, 2, 45 },
        { 4, 2, 10 },
        { 4, 10, 35 },
        { 6, 10, 25 },
        { 6, 7, 20 },
        { 9, 7, 25 },
        { 2, 10, 25 },
        { 7, 10, 15 },
    };

    Network network(numberOfVertices, start, finish);

    for (auto edge : edges)
    {
        VertexNumber from = edge[0]; // 0 ... numberOfVertices - 1
        VertexNumber to = edge[1]; // 0 ... numberOfVertices - 1
        int capacity = edge[2];

        network.AddEdge(from, to, capacity);
    }

    auto& finder = MaxFlowFinder::GetInstance();

    int maximumFlow = finder.FindMaximumFlow(&network);

    finder.PrintMaxFlowAsMatrix();

    std::cout << "Max flow = " << maximumFlow << '\n';

    return 0;
}
