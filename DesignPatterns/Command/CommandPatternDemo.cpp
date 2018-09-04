#include "Stock.h"
#include "BuyStock.h"
#include "SellStock.h"
#include "Broker.h"

int main(int argc, char **argv)
{
	Stock *abcStock = new Stock();

	BuyStock *buyStockOrder = new BuyStock(abcStock);
	SellStock *sellStockOrder = new SellStock(abcStock);

	Broker *broker = new Broker();
	broker->takeOrder(buyStockOrder);
	broker->takeOrder(sellStockOrder);

	broker->placeOrders();

	delete broker;
	delete sellStockOrder;
	delete buyStockOrder;
	delete abcStock;

	return 0;
}