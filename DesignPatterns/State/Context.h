#pragma once

#include "State.h"

struct State;

class Context
{
public:
	Context() = default;
	~Context() = default;

	void setState(State *state) { this->state = state; }
	State *getState() const { return this->state; }

private:
	State * state;
};