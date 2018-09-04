#pragma once

#include "Image.h"
#include <string>

class RealImage : public Image
{
public:
	RealImage(const std::string &filename);
	~RealImage() = default;

	// Í¨¹ý Image ¼Ì³Ð
	virtual void display() override;

private:
	const std::string fileName;

	void loadFromDisk(const std::string &filename);
};