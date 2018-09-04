#pragma once

#include "Observer.h"
#include "Subject.h"

class HexaObserver : public Observer
{
public:
	HexaObserver(Subject *sub);
	~HexaObserver() = default;


	// ͨ�� Observer �̳�
	virtual void update() override;

};