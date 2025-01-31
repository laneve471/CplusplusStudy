#pragma once
#include "pch.h"
#include "Monster.h"
#include <vector>

class Boss : public Monster
{
public:
	Boss();
	Boss(int hp, int atk, string name);
	~Boss();

	void Attack();
	void DeadSound();
	void TakeDamage(int amount, Creature* attack);
	std::vector<Creature*> GetTarget();

private:
	std::vector<Creature*> target;
};