#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::write(const std::string & message)
{
	std::cout << "Standard Console::Logger: " + message << std::endl;
}
