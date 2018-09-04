#pragma once

#include "AbstractLogger.h"

class FileLogger : public AbstractLogger
{
public:
	FileLogger(int level = AbstractLogger::INFO) : AbstractLogger(level) {}
	~FileLogger() = default;

protected:
	// Í¨¹ý AbstractLogger ¼Ì³Ð
	virtual void write(const std::string & message) override;
};