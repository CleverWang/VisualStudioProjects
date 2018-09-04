#pragma once

#include "State.h"
#include <ostream>

struct StopState : public State
{
	// ͨ�� State �̳�
	virtual void doAction(Context * context) override;

	virtual std::string toString() const override;

	//friend std::ostream &operator<<(std::ostream &os, StopState *stopState);
};

//std::ostream &operator<<(std::ostream &os, StopState *stopState)
//{
//	os << "Stop State";
//	return os;
//}