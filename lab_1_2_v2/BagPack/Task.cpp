#include "task.h"
#include "BackPack.h"

constexpr int GenMaxCost = 20;
constexpr int GenMaxWeight = 30;
constexpr int ItemsNumber = 10;
constexpr int T = 80;

Item InitItems(std::vector<Item>& items)
{
    Item itemSummary = {0, 0};

    for (auto i = 0; i < ItemsNumber; i++)
    {
        Item item = {
            rand() % GenMaxWeight + 1,
            rand() % GenMaxCost + 1
        };
        items.push_back(item);
        itemSummary.w += item.w;
        itemSummary.c += item.c;
    }
    return itemSummary;
}

void PrintItems(const std::vector<Item>& items)
{
    for (Item item : items)
    {
        std::cout << item.w << "kg : " << item.c << "$\n";
    }
    std::cout << '\n';
}

void InitItemsOrder(std::vector<int> &itemsOrder)
{
    for (int i = 0; i < ItemsNumber; i++)
    {
        itemsOrder.push_back(i + 1);
    }
}

bool CalculateVariant(const std::vector<Item>& items, const std::vector<int>& order, std::vector<Item>& backPackBest, int& maxCost, int& backPackBestWeigth)
{
    std::vector<Item> backPackCur;
    int cost = 0, weight = 0;

    for (int orderItem : order)
    {
        if ((weight + items[orderItem - 1].w) <= T)
        {
            cost += items[orderItem - 1].c;
            weight += items[orderItem - 1].w;
            backPackCur.push_back(items[orderItem - 1]);
        }
        else
        {
            if (maxCost < cost)
            {
                maxCost = cost;
                backPackBestWeigth = weight;
                backPackBest.clear();
                for (Item item : backPackCur)
                {
                    backPackBest.push_back(item);
                }
                return true;
            }
            break;
        }
    }
    return false;
}

int64_t next_combination_mask(int64_t x)
{
    int64_t a = x & -x;
    int64_t b = x + a;
    int64_t c = b ^ x;
    a <<= 2;
    c /= a;
    return b | c;
}

int main()
{
    boost::timer::auto_cpu_timer t;
    std::srand((int unsigned)std::time(nullptr));

 /*
    std::vector<Item> items{};
    Item itemSummary = InitItems(items);

    std::cout << "All items:" << '\n';
    PrintItems(items);

    std::cout << "Summary: " << itemSummary.w << "kg : " << itemSummary.c << "$\n\nBackpack weight limit: " << T << "\n\n";

    std::cout << "- - - - - - - - - - - - - - - - - - -\n\n";

    int maxCost = 0;
    int backPackBestWeigth = 0;
    std::vector<Item> backPackBest = {};
    std::vector<int> itemsOrder = {};

    InitItemsOrder(itemsOrder);
   
    do
    {
        if (CalculateVariant(items, itemsOrder, backPackBest, maxCost, backPackBestWeigth))
        {
            std::cout << "items:\n";
            for (Item item : backPackBest)
            {
                std::cout << item.w << "kg : " << item.c << "$\n";
            }
            std::cout << "---------\n" << "$ " << maxCost << " [ " << backPackBestWeigth << " kg ]\n\n";
        }

    } while (std::next_permutation(itemsOrder.begin(), itemsOrder.end()));
   
 
    int64_t current = 0x0F; // первая битовая маска;
    int64_t last = 1 << 20; // 52-й бит появится только когда мы рассмотрим все комбинации из 52 карт, и перейдем к 53-й
    do {
        std::cout << current << "\t"; // что-то делаем...
        current = next_combination_mask(current); // переходим к следующей руке
    } while (current < last);
    */

    std::vector<Item> items = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
    };
    int maxWeight = 20;

    BackPack backPack = BackPack(maxWeight, items);
    backPack.SetDebugOutputMode(true);
    backPack.Run();

    return 0;
}
