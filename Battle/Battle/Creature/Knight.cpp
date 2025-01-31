#include "pch.h"
#include "Knight.h"

Knight::Knight(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SetName(name);
};

Knight::~Knight() {};

void Knight::Attack(Creature* other)
{
	cout << "Knight Attack" << endl;
	other->TakeDamage(_atk, this);
	GetDamageSum() += _atk;
};
