#pragma once

#include "ComputerPart.h"

struct Keyboard : public ComputerPart
{
	// Í¨¹ý ComputerPart ¼Ì³Ð
	virtual void accept(ComputerPartVisitor * computerPartVisitor) override;
};