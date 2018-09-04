#pragma once

#include "Packing.h"
#include <string>
#include <memory>

struct Item
{
	virtual std::string name() = 0;
	virtual std::shared_ptr<Packing> packing() = 0;
	virtual float price() = 0;
};