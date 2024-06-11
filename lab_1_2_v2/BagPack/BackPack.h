#pragma once

#include "stdafx.h"

struct Item
{
    int w;
    int c;
};

class BackPack
{
public:
    BackPack(int, const std::vector<Item>&);
    void SetDebugOutputMode(bool isDebug);
    void Run();
    int GetBackPackBestCost();
    int GetBackPackBestWeigth();
    std::vector<Item> GetBackPackBest();
    static int64_t NextCombinationMask(int64_t x)
    {
        int64_t a = x & -x;
        int64_t b = x + a;
        int64_t c = b ^ x;
        a <<= 2;
        c /= a;
        return b | c;
    };
private:
    void Init();
    bool CalculateVariant(uint64_t itemsSet);
    int m_weight_limit;
    std::vector<Item> m_items;
    int m_backPackBestWeigth;
    int m_backPackBestCost;
    std::vector<Item> m_backPackBest;
    bool m_debugModeOutput;
    std::vector<int> m_pows;
    std::vector<int> m_masks;
};
