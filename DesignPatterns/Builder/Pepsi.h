#pragma once

#include "ColdDrink.h"

struct Pepsi : public ColdDrink
{
	// ͨ�� ColdDrink �̳�
	virtual std::string name() override;
	virtual float price() override;
};