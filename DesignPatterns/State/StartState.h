#pragma once

#include "State.h"
#include <ostream>

struct StartState : public State
{
	// ͨ�� State �̳�
	virtual void doAction(Context * context) override;

	virtual std::string toString() const override;

	//friend std::ostream &operator<<(std::ostream &os, StartState *startState);
};

//std::ostream &operator<<(std::ostream &os, StartState *startState)
//{
//	os << "Start State";
//	return os;
//}