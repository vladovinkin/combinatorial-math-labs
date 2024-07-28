#include "BackPack.h"

BackPack::BackPack(int weight, const std::vector<Item>& items)
{
	m_weight_limit = weight;
	m_items = items;
	Init();
}

void BackPack::Init() {
	SetDebugOutputMode(false);
	m_backPackBest = {};
	m_backPackBestWeight = 0;
	m_backPackBestCost = 0;

	// заполнение битовых составляющих и инициализирующих масок
	m_pows.push_back(1);
	m_masks.push_back(1);
	for (auto i = 1; i < m_items.size(); i++)
	{
		m_pows.push_back(m_pows[i - 1] << 1);
		m_masks.push_back(m_masks[i - 1] << 1 | 1);
	}
}

void BackPack::SetDebugOutputMode(bool isDebug)
{
	m_debugModeOutput = isDebug;
}

void BackPack::Run()
{
	int64_t numItems = (int64_t)m_items.size();
	for (auto itemsToPut = numItems; itemsToPut > 0; itemsToPut--)
	{
		int64_t current = m_masks[itemsToPut - 1];
		int64_t last = static_cast <uint64_t>(1) << numItems;
		do 
		{
			//std::cout << current << "\t";
			if (CalculateVariant(current) && m_debugModeOutput)
			{
				// вывод содержимого очередного более удачного сета
				std::cout << "BackPack cost: " << m_backPackBestCost << "\n";
				std::cout << "BackPack weight: " << m_backPackBestWeight << "\n";
				std::cout << "BackPack items:\t";
				for (Item item : m_backPackBest)
				{
					std::cout << item.w << "kg : " << item.c << "$\t";
				}
				std::cout << "\n\n";
			}
			current = BackPack::NextCombinationMask(current); // переходим к следующей руке
		} while (current < last);
	}
}

int BackPack::GetBackPackBestWeight()
{
	return m_backPackBestWeight;
}

int BackPack::GetBackPackBestCost()
{
	return m_backPackBestCost;
}

std::vector<Item> BackPack::GetBackPackBest()
{
	return m_backPackBest;
}

bool BackPack::CalculateVariant(uint64_t itemsSet)
{
	unsigned numItems = (unsigned)m_items.size();
	int cost = 0, weight = 0;
	std::vector<Item> backPackContent = {};

	for (auto i = numItems; i > 0; i--)
	{
		// если очередной предмет - кандидат в рюкзак
		if (itemsSet & m_pows[i - 1])
		{
			// если лезет - положим
			if ((weight + m_items[i - 1].w) <= m_weight_limit)
			{
				weight += m_items[i - 1].w;
				cost += m_items[i - 1].c;
				backPackContent.push_back(m_items[i - 1]);
			}
			else
			{
				// не лезет - остановим наполнение
				break;
			}
		}
	}

	// сравним содержимое с лучшим и, если получилось улучшить, запишем в лучшие
	if (cost > m_backPackBestCost)
	{
		m_backPackBest = backPackContent;
		m_backPackBestWeight = weight;
		m_backPackBestCost = cost;

		return true;
	}

	return false;
}
