#pragma once

#include "Memento.h"
#include <vector>

class CareTaker
{
public:
	CareTaker() = default;
	~CareTaker() { for (auto &memento : mementoList) { delete memento; } }

	void add(Memento *memento) { mementoList.push_back(memento); }
	Memento *get(std::size_t index) { return mementoList[index]; }

private:
	std::vector<Memento*> mementoList;
};