#include "Monitor.h"
#include "ComputerPartVisitor.h"

void Monitor::accept(ComputerPartVisitor * computerPartVisitor)
{
	computerPartVisitor->visit(this);
}
