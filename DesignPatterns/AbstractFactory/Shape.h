#pragma once

struct Shape
{
	virtual void draw() = 0;
	virtual ~Shape() = default;
};