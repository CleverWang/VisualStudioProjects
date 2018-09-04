#pragma once

#include "Item.h"

struct Burger : public Item
{
	// Í¨¹ý Item ¼Ì³Ð
	virtual std::shared_ptr<Packing> packing() override;
};