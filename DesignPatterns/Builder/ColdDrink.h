#pragma once

#include "Item.h"

struct ColdDrink : public Item
{
	// ͨ�� Item �̳�
	virtual std::shared_ptr<Packing> packing() override;
};