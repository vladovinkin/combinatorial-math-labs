#include "task.h"
#include "BackPack.h"

int main()
{
    boost::timer::auto_cpu_timer t;
    std::srand((int unsigned)std::time(nullptr));

    std::vector<Item> items = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {7, 8},
    };
    int maxWeight = 50;

    BackPack backPack = BackPack(maxWeight, items);
    backPack.SetDebugOutputMode(true);
    backPack.Run();

    return 0;
}
