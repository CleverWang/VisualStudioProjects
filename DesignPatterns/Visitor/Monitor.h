#pragma once

#include "ComputerPart.h"

struct Monitor : public ComputerPart
{
	// ͨ�� ComputerPart �̳�
	virtual void accept(ComputerPartVisitor * computerPartVisitor) override;
};