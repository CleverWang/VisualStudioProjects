#include "ErrorLogger.h"
#include <iostream>

void ErrorLogger::write(const std::string & message)
{
	std::cout << "Error Console::Logger: " + message << std::endl;
}
