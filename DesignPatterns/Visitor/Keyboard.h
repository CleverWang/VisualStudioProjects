#pragma once

#include "ComputerPart.h"

struct Keyboard : public ComputerPart
{
	// ͨ�� ComputerPart �̳�
	virtual void accept(ComputerPartVisitor * computerPartVisitor) override;
};