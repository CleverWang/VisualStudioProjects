#pragma once

#include "AdvancedMediaPlayer.h"

struct Mp4Player : public AdvancedMediaPlayer
{
	// Í¨¹ý AdvancedMediaPlayer ¼Ì³Ð
	virtual void playVlc(const std::string & fileName) override;
	virtual void playMp4(const std::string & fileName) override;
};