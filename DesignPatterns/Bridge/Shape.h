#pragma once

#include "DrawAPI.h"

struct Shape
{
	virtual void draw() = 0;
	virtual ~Shape() { delete drawAPI; }
protected:
	DrawAPI * drawAPI;
	Shape(DrawAPI *drawAPI) : drawAPI(drawAPI) {}
};