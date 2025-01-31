#pragma once
#include "pch.h"

#include "Player.h"

class Mage : public Player
{
public:
	Mage(int hp, int atk, string name);
	~Mage();

	void Attack(Creature* other) override;

private:
};