#pragma once
#include "pch.h"

#include "Player.h"

class Knight : public Player
{
public:
	Knight(int hp, int atk, string name);
	~Knight();

	void Attack(Creature* other) override;
	
private:
};