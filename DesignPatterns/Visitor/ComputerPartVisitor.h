#pragma once

struct Keyboard;
struct Mouse;
struct Monitor;
class Computer;

struct ComputerPartVisitor
{
	virtual ~ComputerPartVisitor() = default;

	virtual void visit(Computer *computer) = 0;
	virtual void visit(Mouse *mouse) = 0;
	virtual void visit(Keyboard *keyboard) = 0;
	virtual void visit(Monitor *monitor) = 0;
};