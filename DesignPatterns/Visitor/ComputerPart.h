#pragma once

struct ComputerPartVisitor;

struct ComputerPart
{
	virtual ~ComputerPart() = default;
	virtual void accept(ComputerPartVisitor *computerPartVisitor) = 0;
};