#pragma once

#include "ComputerPartVisitor.h"

struct ComputerPartDisplayVisitor : public ComputerPartVisitor
{
	// Í¨¹ý ComputerPartVisitor ¼Ì³Ð
	virtual void visit(Computer * computer) override;
	virtual void visit(Mouse * mouse) override;
	virtual void visit(Keyboard * keyboard) override;
	virtual void visit(Monitor * monitor) override;
};