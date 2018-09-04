#pragma once

#include <string>

class Stock
{
public:
	Stock() = default;
	~Stock() = default;

	void buy();
	void sell();

private:
	std::string name = "ABC";
	int quantity = 10;
};