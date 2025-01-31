#pragma once

#include "Creature/Creature.h"
class Creature;

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();
	int& GetDamageSum();

private:
	int _damageSum;
};