#pragma once

#include <string>

class AbstractLogger
{
public:
	AbstractLogger(int level = AbstractLogger::INFO) : level(level) {}
	virtual ~AbstractLogger() {
		if (nextLogger != nullptr) delete nextLogger;
	}

	static int INFO;
	static int DEBUG;
	static int ERROR;

	void setNextLogger(AbstractLogger *nextLogger);
	void logMessage(int level, const std::string &message);

protected:
	int level;
	AbstractLogger *nextLogger;

	virtual void write(const std::string &message) = 0;
};