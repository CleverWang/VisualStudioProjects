#pragma once

#include "Observer.h"
#include <vector>

class Observer;

class Subject
{
public:
	Subject() = default;
	~Subject() = default;

	int getState();
	void setState(int state);
	void attach(Observer *observer);
	void notifyAllObservers();

private:
	std::vector<Observer*> observers;
	int state;
};