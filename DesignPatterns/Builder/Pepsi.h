#pragma once

#include "ColdDrink.h"

struct Pepsi : public ColdDrink
{
	// Í¨¹ý ColdDrink ¼Ì³Ð
	virtual std::string name() override;
	virtual float price() override;
};