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

    for (auto i = 0; i < km.size(); i++)
    {
        for (auto j = 0; j < km.size(); j++)
        {
            std::cout << km[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
