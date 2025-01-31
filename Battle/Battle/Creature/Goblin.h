#pragma once
#include "pch.h"
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(int hp, int atk, string name);
	~Goblin();

	void Attack(Creature* other) override;
	void DeadSound();
};