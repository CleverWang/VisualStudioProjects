#include "Keyboard.h"
#include "ComputerPartVisitor.h"

void Keyboard::accept(ComputerPartVisitor * computerPartVisitor)
{
	computerPartVisitor->visit(this);
}
