#pragma once

#include "Packing.h"

struct Wrapper : public Packing
{
	// ͨ�� Packing �̳�
	virtual std::string pack() override;
};