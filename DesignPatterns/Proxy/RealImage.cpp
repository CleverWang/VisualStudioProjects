#include "RealImage.h"
#include <iostream>

RealImage::RealImage(const std::string & filename) : fileName(filename)
{
	loadFromDisk(fileName);
}

void RealImage::display()
{
	std::cout << "Displaying " + fileName << std::endl;
}

void RealImage::loadFromDisk(const std::string & filename)
{
	std::cout << "Loading " + fileName << std::endl;
}
