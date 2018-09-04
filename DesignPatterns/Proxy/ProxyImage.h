#pragma once

#include "Image.h"
#include "RealImage.h"
#include <memory>

class ProxyImage : public Image
{
public:
	ProxyImage(const std::string &filename);
	~ProxyImage() = default;

	// Í¨¹ý Image ¼Ì³Ð
	virtual void display() override;

private:
	const std::string fileName;
	std::unique_ptr<RealImage> realImage;
};