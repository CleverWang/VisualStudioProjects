#pragma once

#include <string>

struct MediaPlayer
{
	virtual void play(const std::string &audioType, const std::string &fileName) = 0;
	virtual ~MediaPlayer() = default;
};