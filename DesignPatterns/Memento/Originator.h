#pragma once

#include <string>

class Memento;

class Originator
{
public:
	Originator() = default;
	~Originator() = default;

	void setState(const std::string &state) { this->state = state; }
	std::string getState() const { return this->state; }
	Memento *saveStateToMemento();
	void getStateFromMemento(Memento *memento);

private:
	std::string state;
};
