#pragma once

#include "ComputerPart.h"
#include "Monitor.h"
#include "Mouse.h"
#include "Keyboard.h"
#include <vector>

class Computer : public ComputerPart
{
public:
	Computer() : parts({ new Mouse(), new Keyboard(), new Monitor() }) {}
	~Computer() { for (auto &part : parts) { delete part; } }

	// ͨ�� ComputerPart �̳�
	virtual void accept(ComputerPartVisitor * computerPartVisitor) override;

private:
	std::vector<ComputerPart*> parts;
};