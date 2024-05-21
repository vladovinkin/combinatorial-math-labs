#include "task.h"

struct Item
{
    int w;
    int c;
};

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

bool CalculateVariant(const std::vector<Item>& items, const std::vector<int>& order, std::vector<Item>& backPackBest, int& maxCost)
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

int main()
{
    boost::timer::auto_cpu_timer t;
    std::srand(std::time(nullptr));

    std::vector<Item> items{};
    Item itemSummary = InitItems(items);

    std::cout << "All items:" << '\n';
    PrintItems(items);

    std::cout << "Summary: " << itemSummary.w << "kg : " << itemSummary.c << "$\n\n";

    std::cout << "- - - - - - - - - - - - - - - - - - -\n\n";

    int maxCost = 0;
    std::vector<Item> backPackBest = {};
    std::vector<int> itemsOrder = {};

    InitItemsOrder(itemsOrder);
   
    do
    {
        if (CalculateVariant(items, itemsOrder, backPackBest, maxCost))
        {
            std::cout << "items:\n";
            for (Item item : backPackBest)
            {
                std::cout << item.w << "kg : " << item.c << "$\n";
            }
            std::cout << "---------\n" << "$ = " << maxCost << "\n\n";
        }

    } while (std::next_permutation(itemsOrder.begin(), itemsOrder.end()));
    
    return 0;
}
