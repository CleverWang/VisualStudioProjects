#pragma once

#include "Burger.h"

struct VegBurger : public Burger
{
	// ͨ�� Burger �̳�
	virtual std::string name() override;
	virtual float price() override;
};