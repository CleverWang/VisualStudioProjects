#pragma once

#include "AbstractLogger.h"

class ConsoleLogger : public AbstractLogger
{
public:
	ConsoleLogger(int level = AbstractLogger::INFO) : AbstractLogger(level) {}
	~ConsoleLogger() = default;

protected:
	// Í¨¹ý AbstractLogger ¼Ì³Ð
	virtual void write(const std::string & message) override;
};