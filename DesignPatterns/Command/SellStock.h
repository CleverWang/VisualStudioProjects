#pragma once

#include "Order.h"
#include "Stock.h"

class SellStock : public Order
{
public:
	SellStock(Stock *abcStock) : abcStock(abcStock) {}
	~SellStock() = default;

	// ͨ�� Order �̳�
	virtual void execute() override;

private:
	Stock * abcStock;
};