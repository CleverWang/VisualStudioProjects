#include "BinaryObserver.h"
#include <iostream>
#include <stack>

BinaryObserver::BinaryObserver(Subject * sub) : Observer(sub)
{
	subject->attach(this);
}

void BinaryObserver::update()
{
	std::cout << "Binary String: ";
	std::stack<bool> bin;
	int state = subject->getState();
	int temp;
	while (temp = state / 2)
	{
		bin.push(state % 2);
		state = temp;
	}
	bin.push(1);
	while (!bin.empty())
	{
		std::cout << bin.top();
		bin.pop();
	}
	std::cout << std::endl;
}
