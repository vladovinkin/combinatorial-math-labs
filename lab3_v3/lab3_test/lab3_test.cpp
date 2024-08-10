#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"
#include "../lab3_v3_project/Graph.h"
#include "../lab3_v3_project/Faces.h"

void ReverseVector(std::vector<int>& data)
{
    std::vector<int> temp{};
    while (data.size() > 0)
    {
        temp.push_back(data[data.size() - 1]);
        data.pop_back();
    }
    data = temp;
}

bool IsEqualFaces(const std::vector<int>& face1, const std::vector<int>& face2)
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

bool IsContainFace(const std::vector<std::vector<int>>& interior, const std::vector<int>& face)
{
    for (auto i = 0; i < interior.size(); i++)
    {
        if (IsEqualFaces(interior[i], face))
        {
            return true;
        }
    }
    return false;
}

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

    std::vector<std::vector<int>> interior = planar.GetInterior();
    std::vector<int> external = planar.GetExternal();

    // Ожидаемый результат
    std::vector<int> external_ref{3, 1, 0};
    std::vector<std::vector<int>> interior_ref = {
        { 1, 3, 2 },
        { 1, 4, 5, 0 },
        { 2, 4, 1 },
        { 3, 4, 2 },
        { 4, 6, 5 },
        { 5, 6, 4, 3, 0 },
    };

    // проверка внешней грани
    CHECK(IsEqualFaces(external, external_ref));

    // проверка внутренних граней
    for (auto interior_face : interior_ref)
    {
        CHECK(IsContainFace(interior, interior_face));
    }
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

    std::vector<std::vector<int>> interior = planar.GetInterior();
    std::vector<int> external = planar.GetExternal();

    // Ожидаемый результат
    std::vector<int> external_ref{ 2, 3, 7, 6 };
    std::vector<std::vector<int>> interior_ref = {
        { 0, 1, 2, 3 },
        { 0, 4, 5, 1 },
        { 2, 1, 5, 6 },
        { 0, 4, 7, 3 },
        { 4, 5, 6, 7 },
    };

    // проверка внешней грани
    CHECK(IsEqualFaces(external, external_ref));

    // проверка внутренних граней
    for (auto interior_face : interior_ref)
    {
        CHECK(IsContainFace(interior, interior_face));
    }
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

    std::vector<std::vector<int>> interior = planar.GetInterior();
    std::vector<int> external = planar.GetExternal();

    // Ожидаемый результат
    std::vector<int> external_ref{ 0, 2, 3 };
    std::vector<std::vector<int>> interior_ref = {
        { 0, 1, 2 },
        { 0, 1, 3 },
        { 1, 2, 3 },
    };

    // проверка внешней грани
    CHECK(IsEqualFaces(external, external_ref));

    // проверка внутренних граней
    for (auto interior_face : interior_ref)
    {
        CHECK(IsContainFace(interior, interior_face));
    }
}
