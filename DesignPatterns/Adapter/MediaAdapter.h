#pragma once

#include "AdvancedMediaPlayer.h"
#include "MediaPlayer.h"
#include <memory>
#include <string>

class MediaAdapter : public MediaPlayer
{
public:
	MediaAdapter(const std::string &audioType);
	~MediaAdapter() = default;

	// Í¨¹ý MediaPlayer ¼Ì³Ð
	virtual void play(const std::string & audioType, const std::string & fileName) override;

private:
	std::unique_ptr<AdvancedMediaPlayer> advancedMusicPlayer;
};