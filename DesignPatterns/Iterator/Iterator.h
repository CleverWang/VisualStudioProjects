#pragma once

struct Iterator
{
	virtual bool hasNext() = 0;
	virtual void *next() = 0;
	virtual ~Iterator() = default;
};