#pragma once

#include "Game.h"

struct Cricket : public Game
{
	// ͨ�� Game �̳�
	virtual void initialize() override;
	virtual void startPlay() override;
	virtual void endPlay() override;
};