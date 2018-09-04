#pragma once

#include "AbstractLogger.h"

class ErrorLogger : public AbstractLogger
{
public:
	ErrorLogger(int level = AbstractLogger::INFO) : AbstractLogger(level) {}
	~ErrorLogger() = default;

protected:
	// ͨ�� AbstractLogger �̳�
	virtual void write(const std::string & message) override;
};