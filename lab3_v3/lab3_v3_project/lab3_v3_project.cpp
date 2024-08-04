#include <iostream>
#include "Faces.h"
#include <algorithm>

int main()
{
    std::vector<int> ext{1,2,3,4,5};
    std::vector<std::vector<int>> inter{
        { 1,2,3,4,5 },
        { 11,12,13,14,15 },
        { 21,22,23,24,25 },
        { 31,32,33,34,35 },
        { 41,42,43,44,45 },
    };
    Faces f = Faces(inter, ext);

    std::cout << "Hello World!\n";
    std::cout << f.ToString();

    std::vector<int> first{1, 2, 3};
    std::vector<int> second{11, 12, 13};

    first.insert(first.end(), second.begin(), second.end());
    for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    {
        std::cout << *it << "\t";
    }
}
