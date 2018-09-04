#include "Subject.h"

int Subject::getState()
{
	return state;
}

void Subject::setState(int state)
{
	this->state = state;
	notifyAllObservers();
}

void Subject::attach(Observer * observer)
{
	observers.push_back(observer);
}

void Subject::notifyAllObservers()
{
	for (auto &ob : observers)
	{
		ob->update();
	}
}
