#include <iostream>
#include "TreeCount.h"

int main()
{
    Matrix m{
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    auto tc = TreeCount(m);

    Matrix km = tc.GetKirchhoffMatrix();
    std::cout << tc.GetCountTree() << "\n";

    return 0;
}
