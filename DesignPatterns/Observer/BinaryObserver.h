#pragma once

#include "Observer.h"

class BinaryObserver : public Observer
{
public:
	BinaryObserver(Subject *sub);
	~BinaryObserver() = default;


	// Í¨¹ý Observer ¼Ì³Ð
	virtual void update() override;

};