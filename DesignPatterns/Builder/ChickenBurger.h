#pragma once

#include "Burger.h"

struct ChickenBurger : public Burger
{
	// Í¨¹ý Burger ¼Ì³Ð
	virtual std::string name() override;
	virtual float price() override;
};