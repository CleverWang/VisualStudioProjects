#pragma once

#include "ComputerPart.h"

struct Mouse : public ComputerPart
{
	// ͨ�� ComputerPart �̳�
	virtual void accept(ComputerPartVisitor * computerPartVisitor) override;
};