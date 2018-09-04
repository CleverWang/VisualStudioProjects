#pragma once

#include "ComputerPart.h"

struct Monitor : public ComputerPart
{
	// Í¨¹ý ComputerPart ¼Ì³Ð
	virtual void accept(ComputerPartVisitor * computerPartVisitor) override;
};