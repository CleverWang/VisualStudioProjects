#pragma once

#include "Burger.h"

struct ChickenBurger : public Burger
{
	// ͨ�� Burger �̳�
	virtual std::string name() override;
	virtual float price() override;
};