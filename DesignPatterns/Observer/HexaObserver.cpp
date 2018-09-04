#include "HexaObserver.h"
#include <stdio.h>

HexaObserver::HexaObserver(Subject * sub) : Observer(sub)
{
	subject->attach(this);
}

void HexaObserver::update()
{
	printf_s("Hex String: %X\n", subject->getState());
}
