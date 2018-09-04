#include "ComputerPartDisplayVisitor.h"
#include "Computer.h"
#include "Monitor.h"
#include "Mouse.h"
#include "Keyboard.h"
#include <iostream>

void ComputerPartDisplayVisitor::visit(Computer * computer)
{
	std::cout << "Displaying Computer.\n";
}

void ComputerPartDisplayVisitor::visit(Mouse * mouse)
{
	std::cout << "Displaying Mouse.\n";
}

void ComputerPartDisplayVisitor::visit(Keyboard * keyboard)
{
	std::cout << "Displaying Keyboard.\n";
}

void ComputerPartDisplayVisitor::visit(Monitor * monitor)
{
	std::cout << "Displaying Monitor.\n";
}
