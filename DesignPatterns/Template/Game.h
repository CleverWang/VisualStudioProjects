#pragma once

struct Game
{
	virtual ~Game() = default;
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;

	// ģ�壨��ֹ������дģ�壩
	virtual void play() final;
};