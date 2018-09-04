#pragma once

#include "Observer.h"
#include "Subject.h"

class HexaObserver : public Observer
{
public:
	HexaObserver(Subject *sub);
	~HexaObserver() = default;


	// Í¨¹ý Observer ¼Ì³Ð
	virtual void update() override;

};