#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"
#include "../Hungarian/Hungarian.h"

TEST_CASE("Matrix 4x4")
{
    setlocale(LC_ALL, "rus");

    Matrix src{
        {INF, 7, 1, 3},
        {1, 6, 4, 6},
        {17, 1, 5, 1},
        {INF, 6, 10, 4}
    };

    std::vector<int> expectedAssignment = { 2, 0, 1, 3 };
    int expectedTotalCost = 7;

    Hungarian hungarian = Hungarian(src);
    hungarian.Algorithm();

    CHECK(hungarian.GetAssignment() == expectedAssignment);
    CHECK(hungarian.GetTotalCost() == expectedTotalCost);
}

TEST_CASE("Matrix 5x5")
{
    setlocale(LC_ALL, "rus");

    Matrix src{
        {9, 2, 7, 8, 6},
        {6, 4, 3, 7, 5},
        {5, 8, 1, 8, 3},
        {7, INF, 9, 4, 2},
        {INF, 8, 4, 3, 7}
    };

    std::vector<int> expectedAssignment = { 1, 0, 2, 4, 3 };
    int expectedTotalCost = 14;

    Hungarian hungarian = Hungarian(src);
    hungarian.Algorithm();

    CHECK(hungarian.GetAssignment() == expectedAssignment);
    CHECK(hungarian.GetTotalCost() == expectedTotalCost);
}

TEST_CASE("Matrix 7x7")
{
    setlocale(LC_ALL, "rus");

    Matrix src{
        { 50, INF, INF, 10, INF, 20, INF },
        { INF, 30, 45, INF, 30, INF, 25 },
        { INF, 5, INF, INF, 10, 15, INF },
        { 15, INF, INF, 20, INF, INF, INF },
        { INF, INF, 20, INF, INF, 5, INF },
        { INF, INF, INF, INF, 40, INF, 5 },
        { INF, INF, INF, 15, INF, INF, INF },
    };

    std::vector<int> expectedAssignment = { 5, 4, 1, 0, 2, 6, 3 };
    int expectedTotalCost = 110;

    Hungarian hungarian = Hungarian(src);
    hungarian.Algorithm();

    CHECK(hungarian.GetAssignment() == expectedAssignment);
    CHECK(hungarian.GetTotalCost() == expectedTotalCost);
}
