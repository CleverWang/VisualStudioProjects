#pragma once

#include <string>

class Memento
{
public:
	Memento(const std::string &state) : state(state) {}
	~Memento() = default;

	std::string getState() const { return state; }

private:
	std::string state;
};