#pragma once

#include "MediaPlayer.h"
#include "MediaAdapter.h"

class AudioPlayer : public MediaPlayer
{
public:
	AudioPlayer() = default;
	~AudioPlayer() = default;

	// Í¨¹ý MediaPlayer ¼Ì³Ð
	virtual void play(const std::string & audioType, const std::string & fileName) override;

private:
	std::unique_ptr<MediaAdapter> mediaAdapter;
};
