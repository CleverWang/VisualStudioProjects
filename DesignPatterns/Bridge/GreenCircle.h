#pragma once

#include "DrawAPI.h"

struct GreenCircle : public DrawAPI
{
	// Í¨¹ý DrawAPI ¼Ì³Ð
	virtual void drawCircle(int r, int x, int y) override;
};