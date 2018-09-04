#pragma once
#include <string>

class User
{
public:
	User(const std::string &name) : name(name) {}
	~User() = default;

	void setName(const std::string &name) { this->name = name; }
	std::string getName() { return this->name; }

	void sendMessage(const std::string &message);

private:
	std::string name;
};