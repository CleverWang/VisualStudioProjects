#pragma once

#include "AdvancedMediaPlayer.h"

struct VlcPlayer : public AdvancedMediaPlayer
{
	// ͨ�� AdvancedMediaPlayer �̳�
	virtual void playVlc(const std::string & fileName) override;
	virtual void playMp4(const std::string & fileName) override;
};