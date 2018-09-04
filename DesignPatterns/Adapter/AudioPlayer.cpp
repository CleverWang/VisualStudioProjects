#include "AudioPlayer.h"
#include <iostream>

void AudioPlayer::play(const std::string & audioType, const std::string & fileName)
{
	if (audioType == "mp3")
	{
		std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
	}
	else if (audioType == "vlc" || audioType == "mp4")
	{
		mediaAdapter.reset(new MediaAdapter(audioType));
		mediaAdapter->play(audioType, fileName);
	}
	else
	{
		std::cout << "Invalid media. " + audioType + " format not supported\n";
	}
}
