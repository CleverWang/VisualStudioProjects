#pragma once

#include "DrawAPI.h"

struct GreenCircle : public DrawAPI
{
	// ͨ�� DrawAPI �̳�
	virtual void drawCircle(int r, int x, int y) override;
};