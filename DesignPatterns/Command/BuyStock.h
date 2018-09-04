#pragma once

#include "Order.h"
#include "Stock.h"

class BuyStock : public Order
{
public:
	BuyStock(Stock *abcStock) : abcStock(abcStock) {}
	~BuyStock() = default;

	// ͨ�� Order �̳�
	virtual void execute() override;

private:
	Stock * abcStock;
};