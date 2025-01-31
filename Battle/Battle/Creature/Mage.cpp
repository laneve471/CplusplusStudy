#include "pch.h"
#include "Mage.h"

Mage::Mage(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SetName(name);
};

Mage::~Mage() {};

void Mage::Attack(Creature* other)
{
	cout << "Mage Attack" << endl;
	other->TakeDamage(_atk, this);
	GetDamageSum() += _atk;
};