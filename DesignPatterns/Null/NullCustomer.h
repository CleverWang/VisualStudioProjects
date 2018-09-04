#pragma once

#include "AbstractCustomer.h"

struct NullCustomer : public AbstractCustomer
{
	NullCustomer() = default;
	~NullCustomer() = default;

	// Í¨¹ý AbstractCustomer ¼Ì³Ð
	virtual bool isNil() const override;
	virtual std::string getName() const override;
};