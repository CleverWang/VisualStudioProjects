#pragma once

#include "AbstractLogger.h"

class ErrorLogger : public AbstractLogger
{
public:
	ErrorLogger(int level = AbstractLogger::INFO) : AbstractLogger(level) {}
	~ErrorLogger() = default;

protected:
	// Í¨¹ý AbstractLogger ¼Ì³Ð
	virtual void write(const std::string & message) override;
};