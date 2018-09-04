#pragma once

#include "Game.h"

struct Cricket : public Game
{
	// Í¨¹ý Game ¼Ì³Ð
	virtual void initialize() override;
	virtual void startPlay() override;
	virtual void endPlay() override;
};