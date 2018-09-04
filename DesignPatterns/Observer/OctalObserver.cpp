#include "OctalObserver.h"
#include "stdio.h"

OctalObserver::OctalObserver(Subject * sub) : Observer(sub)
{
	subject->attach(this);
}

void OctalObserver::update()
{
	printf_s("Octal String: %o\n", subject->getState());
}
