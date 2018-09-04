#pragma once

#include "AbstractCustomer.h"

struct NullCustomer : public AbstractCustomer
{
	NullCustomer() = default;
	~NullCustomer() = default;

	// ͨ�� AbstractCustomer �̳�
	virtual bool isNil() const override;
	virtual std::string getName() const override;
};