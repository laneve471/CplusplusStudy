#pragma once
#include "pch.h"

#include "Creature.h"

class Monster : public Creature
{
public:
	Monster(int hp, int atk);
	~Monster();
};
