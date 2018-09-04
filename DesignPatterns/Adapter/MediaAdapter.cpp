#include "MediaAdapter.h"
#include "VlcPlayer.h"
#include "Mp4Player.h"

MediaAdapter::MediaAdapter(const std::string & audioType)
{
	if (audioType == "vlc")
	{
		advancedMusicPlayer.reset(new VlcPlayer);
	}
	else if (audioType == "mp4")
	{
		advancedMusicPlayer.reset(new Mp4Player);
	}
}

void MediaAdapter::play(const std::string & audioType, const std::string & fileName)
{
	if (audioType == "vlc")
	{
		advancedMusicPlayer->playVlc(fileName);
	}
	else if (audioType == "mp4")
	{
		advancedMusicPlayer->playMp4(fileName);
	}
}
