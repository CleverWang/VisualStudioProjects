#pragma once

#include "Item.h"

struct Burger : public Item
{
	// ͨ�� Item �̳�
	virtual std::shared_ptr<Packing> packing() override;
};