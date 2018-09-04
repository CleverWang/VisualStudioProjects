#include "FileLogger.h"
#include <iostream>

void FileLogger::write(const std::string & message)
{
	std::cout << "File::Logger: " + message << std::endl;
}
