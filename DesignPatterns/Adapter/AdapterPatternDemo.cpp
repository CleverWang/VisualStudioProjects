#include "AudioPlayer.h"

int main(int argc, char **argv)
{
	AudioPlayer audioPlayer;

	audioPlayer.play("mp3", "beyond the horizon.mp3");
	audioPlayer.play("mp4", "alone.mp4");
	audioPlayer.play("vlc", "far far away.vlc");
	audioPlayer.play("avi", "mind me.avi");

	system("pause");

	return 0;
}