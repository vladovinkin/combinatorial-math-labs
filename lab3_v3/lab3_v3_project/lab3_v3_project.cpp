#include <iostream>
#include "Faces.h"
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph1{
        { 0,1,1,1 },
        { 1,0,1,1 },
        { 1,1,0,1 },
        { 1,1,1,0 },
    };

    std::vector<std::vector<int>> graph2{
        { 0,1,1,1,1 },
        { 1,0,1,1,1 },
        { 1,1,0,1,1 },
        { 1,1,1,0,1 },
        { 1,1,1,1,0 },
    };

    std::vector<std::vector<int>> graph3{
        { 0, 1, 0, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 0, 0 },
        { 0, 1, 0, 1, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 0, 0 },
        { 0, 1, 1, 1, 0, 1, 1 },
        { 1, 0, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 1, 0 },
    };

    Graph gr = Graph(graph3);
    Faces planar = gr.GetPlanarLaying();
    if (planar.GetSize() != 0)
    {
        std::cout << "Граф планарный! Грани плоского графа: \n";
        std::cout << planar.ToString() << "\n";
    }
    else
    {
        std::cout << "Граф не планарный!\n";
    }

    return 0;
}
