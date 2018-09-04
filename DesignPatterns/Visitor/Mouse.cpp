#include "Mouse.h"
#include "ComputerPartVisitor.h"

void Mouse::accept(ComputerPartVisitor * computerPartVisitor)
{
	computerPartVisitor->visit(this);
}
