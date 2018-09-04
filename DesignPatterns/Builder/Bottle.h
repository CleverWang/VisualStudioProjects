#pragma once

#include "Packing.h"

struct Bottle : public Packing
{
	// Í¨¹ý Packing ¼Ì³Ð
	virtual std::string pack() override;
};