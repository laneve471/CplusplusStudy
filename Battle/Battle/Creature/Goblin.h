#pragma once

#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(int hp, int atk, string name);
	~Goblin();

	virtual void Attack(shared_ptr<Creature> other) override;
	void DeadSound();

private:
};