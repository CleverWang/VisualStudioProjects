#pragma once

struct Game
{
	virtual ~Game() = default;
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;

	// 模板（阻止子类重写模板）
	virtual void play() final;
};