#pragma once

struct Order
{
	virtual void execute() = 0;
	virtual ~Order() = default;
};