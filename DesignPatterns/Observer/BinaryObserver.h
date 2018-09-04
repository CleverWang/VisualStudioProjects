#pragma once

#include "Observer.h"

class BinaryObserver : public Observer
{
public:
	BinaryObserver(Subject *sub);
	~BinaryObserver() = default;


	// ͨ�� Observer �̳�
	virtual void update() override;

};