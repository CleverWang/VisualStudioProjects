#pragma once

#include "Order.h"
#include <vector>

class Broker
{
public:
	Broker() = default;
	~Broker() = default;

	void takeOrder(Order *order);
	void placeOrders();

private:
	std::vector<Order*> orderList;
};