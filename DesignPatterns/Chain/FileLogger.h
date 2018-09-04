#pragma once

#include "AbstractLogger.h"

class FileLogger : public AbstractLogger
{
public:
	FileLogger(int level = AbstractLogger::INFO) : AbstractLogger(level) {}
	~FileLogger() = default;

protected:
	// ͨ�� AbstractLogger �̳�
	virtual void write(const std::string & message) override;
};