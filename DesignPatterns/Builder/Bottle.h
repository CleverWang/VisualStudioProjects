#pragma once

#include "Packing.h"

struct Bottle : public Packing
{
	// ͨ�� Packing �̳�
	virtual std::string pack() override;
};