#pragma once

#include "Subject.h"
#include <memory>

class Subject;

class Observer
{
public:
	Observer(Subject *sub) : subject(sub) {}
	virtual ~Observer() = default;

	virtual void update() = 0;

protected:
	Subject *subject;
};