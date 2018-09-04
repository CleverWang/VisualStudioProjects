#pragma once

struct Color
{
	virtual void fill() = 0;
	virtual ~Color() = default;
};