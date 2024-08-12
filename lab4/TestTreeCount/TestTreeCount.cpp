#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../oop-homeworks/catch2/catch.hpp"
#include "../TreeCount/TreeCount.h"


/*
      1   4
     / \
    2---3
*/

TEST_CASE("Тест 0")
{
    setlocale(LC_ALL, "rus");

    Matrix m{
       { 0, 1, 1, 0 },
       { 1, 0, 1, 0 },
       { 1, 1, 0, 0 },
       { 0, 0, 0, 0 },
    };

    auto tc = TreeCount(m);

    Matrix km = tc.GetKirchhoffMatrix();
    CHECK(tc.GetCountTree() == 0);
}

/*
    1
  / | \
 2--3--4

 */
TEST_CASE("Тест 1")
{
	setlocale(LC_ALL, "rus");

    Matrix m{
       { 0, 1, 1, 1 },
       { 1, 0, 1, 0 },
       { 1, 1, 0, 1 },
       { 1, 0, 1, 0 },
    };

    auto tc = TreeCount(m);

    Matrix km = tc.GetKirchhoffMatrix();
    CHECK(tc.GetCountTree() == 8);
}

TEST_CASE("Пример из лекции")
{
    setlocale(LC_ALL, "rus");

    Matrix m{
       { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
       { 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
       { 0, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
       { 0, 0, 1, 0, 0, 1, 0, 1, 0, 1 },
       { 0, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
       { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 },
       { 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 },
       { 0, 0, 0, 0, 0, 1, 1, 1, 0, 1 },
       { 0, 0, 0, 0, 1, 0, 0, 1, 1, 0 },
    };

    auto tc = TreeCount(m);

    Matrix km = tc.GetKirchhoffMatrix();
    CHECK(tc.GetCountTree() == 3422);
}
