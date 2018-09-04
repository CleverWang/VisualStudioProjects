#include "ComputerPart.h"
#include "ComputerPartDisplayVisitor.h"
#include "Computer.h"

int main(int argc, char **argv)
{
	ComputerPart *computer = new Computer();
	ComputerPartVisitor *computerPartVisitor = new ComputerPartDisplayVisitor();
	computer->accept(computerPartVisitor);

	delete computerPartVisitor;
	delete computer;

	return 0;
}