#pragma once

#include "AbstractLogger.h"

class ConsoleLogger : public AbstractLogger
{
public:
	ConsoleLogger(int level = AbstractLogger::INFO) : AbstractLogger(level) {}
	~ConsoleLogger() = default;

protected:
	// ͨ�� AbstractLogger �̳�
	virtual void write(const std::string & message) override;
};