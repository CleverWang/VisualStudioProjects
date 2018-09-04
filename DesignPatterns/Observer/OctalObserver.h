#pragma once

#include "Observer.h"
#include "Subject.h"

class OctalObserver : public Observer
{
public:
	OctalObserver(Subject *sub);
	~OctalObserver() = default;

	// ͨ�� Observer �̳�
	virtual void update() override;

};