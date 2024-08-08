#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"
#include "../lab3_v3_project/Graph.h"
#include "../lab3_v3_project/Faces.h"

TEST_CASE("Планарный граф 7х7")
{
	setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph{
    { 0, 1, 0, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 1, 0, 0 },
    { 1, 1, 1, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0, 1, 1 },
    { 1, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 1, 0 },
    };

    Graph gr = Graph(graph);
    Faces planar = gr.GetPlanarLaying();

	CHECK(planar.GetSize() != 0);
}

TEST_CASE("K5 - непланарный граф")
{
    setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph{
        { 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1 },
        { 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 0 },
    };

    Graph gr = Graph(graph);
    Faces planar = gr.GetPlanarLaying();

    CHECK(planar.GetSize() == 0);
}

TEST_CASE("K3,3 - не планарный граф")
{
    setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph{
        { 0, 0, 0, 1, 1, 1 },
        { 0, 0, 0, 1, 1, 1 },
        { 0, 0, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 0 },
    };

    Graph gr = Graph(graph);
    Faces planar = gr.GetPlanarLaying();

    CHECK(planar.GetSize() == 0);
}

TEST_CASE("Граф Петерсона - непланарный граф")
{
    setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph{
        { 0, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
        { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    };

    Graph gr = Graph(graph);
    Faces planar = gr.GetPlanarLaying();

    CHECK(planar.GetSize() == 0);
}

TEST_CASE("Q3 - Гиперкуб размерности 3 - планарный граф")
{
    setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph{
        { 0, 1, 0, 1, 1, 0, 0, 0 },
        { 1, 0, 1, 0, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0, 0, 1, 0 },
        { 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0, 1 },
        { 0, 1, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 1, 1, 0, 1, 0 },
    };

    Graph gr = Graph(graph);
    Faces planar = gr.GetPlanarLaying();

    CHECK(planar.GetSize() != 0);
}

TEST_CASE("K4 - планарный граф")
{
    setlocale(LC_ALL, "rus");

    std::vector<std::vector<int>> graph{
        { 0, 1, 1, 1 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 1 },
        { 1, 1, 1, 0 },
    };

    Graph gr = Graph(graph);
    Faces planar = gr.GetPlanarLaying();

    CHECK(planar.GetSize() != 0);
}
