#pragma once

#include "ColdDrink.h"

struct Coke : public ColdDrink
{
	// ͨ�� ColdDrink �̳�
	virtual std::string name() override;
	virtual float price() override;
};