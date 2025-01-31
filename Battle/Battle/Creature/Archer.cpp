#include "pch.h"
#include "Archer.h"

Archer::Archer(int hp, int atk, string name)
: Player(hp, atk, name)
{
	SetName(name);
};

Archer::~Archer() {};

void Archer::Attack(Creature* other)
{
	cout << "Archer Attack" << endl;
	other->TakeDamage(_atk, this);
	GetDamageSum() += _atk;
};