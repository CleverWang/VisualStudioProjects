#pragma once

#include "Packing.h"

struct Wrapper : public Packing
{
	// Í¨¹ý Packing ¼Ì³Ð
	virtual std::string pack() override;
};