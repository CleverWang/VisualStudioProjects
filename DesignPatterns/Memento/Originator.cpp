#include "Originator.h"
#include "Memento.h"

Memento * Originator::saveStateToMemento()
{
	return new Memento(state);
}

void Originator::getStateFromMemento(Memento * memento)
{
	this->state = memento->getState();
}
