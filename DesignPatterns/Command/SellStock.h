#pragma once

#include "Order.h"
#include "Stock.h"

class SellStock : public Order
{
public:
	SellStock(Stock *abcStock) : abcStock(abcStock) {}
	~SellStock() = default;

	// Í¨¹ý Order ¼Ì³Ð
	virtual void execute() override;

private:
	Stock * abcStock;
};