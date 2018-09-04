#pragma once

#include "Iterator.h"

struct Container
{
	virtual Iterator *getIterator() = 0;
	virtual ~Container() = default;
};