#include "Computer.h"
#include "ComputerPartVisitor.h"

void Computer::accept(ComputerPartVisitor * computerPartVisitor)
{
	for (auto &part : parts)
	{
		part->accept(computerPartVisitor);
	}
	computerPartVisitor->visit(this);
}
