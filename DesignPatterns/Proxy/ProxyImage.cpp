#include "ProxyImage.h"

ProxyImage::ProxyImage(const std::string & filename) : fileName(filename)
{
}

void ProxyImage::display()
{
	if (realImage == nullptr)
	{
		realImage.reset(new RealImage(fileName));
	}
	realImage->display();
}
