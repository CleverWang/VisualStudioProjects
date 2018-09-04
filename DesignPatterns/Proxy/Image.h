#pragma once

struct Image
{
	virtual void display() = 0;
	virtual ~Image() = default;
};