#pragma once

#include "AdvancedMediaPlayer.h"

struct Mp4Player : public AdvancedMediaPlayer
{
	// ͨ�� AdvancedMediaPlayer �̳�
	virtual void playVlc(const std::string & fileName) override;
	virtual void playMp4(const std::string & fileName) override;
};