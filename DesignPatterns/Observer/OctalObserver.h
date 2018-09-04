#pragma once

#include "Observer.h"
#include "Subject.h"

class OctalObserver : public Observer
{
public:
	OctalObserver(Subject *sub);
	~OctalObserver() = default;

	// Í¨¹ý Observer ¼Ì³Ð
	virtual void update() override;

};