#pragma once

#include "AbstractCustomer.h"

struct RealCustomer : public AbstractCustomer
{
	RealCustomer(const std::string &name) : AbstractCustomer(name) {}
	~RealCustomer() = default;

	// ͨ�� AbstractCustomer �̳�
	virtual bool isNil() const override;
	virtual std::string getName() const override;
};