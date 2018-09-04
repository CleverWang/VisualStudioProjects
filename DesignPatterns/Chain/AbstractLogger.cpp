#include "AbstractLogger.h"

int AbstractLogger::INFO = 1;
int AbstractLogger::DEBUG = 2;
int AbstractLogger::ERROR = 3;

void AbstractLogger::setNextLogger(AbstractLogger * nextLogger)
{
	this->nextLogger = nextLogger;
}

void AbstractLogger::logMessage(int level, const std::string & message)
{
	if (this->level <= level)
	{
		write(message);
	}
	if (nextLogger != nullptr)
	{
		nextLogger->logMessage(level, message);
	}
}
