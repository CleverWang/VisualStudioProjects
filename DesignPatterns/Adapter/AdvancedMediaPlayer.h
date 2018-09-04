#pragma once

#include <string>

struct AdvancedMediaPlayer
{
	virtual void playVlc(const std::string &fileName) = 0;
	virtual void playMp4(const std::string &fileName) = 0;
	virtual ~AdvancedMediaPlayer() = default;
};