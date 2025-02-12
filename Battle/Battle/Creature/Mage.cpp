#include "pch.h"
#include "Mage.h"

Mage::Mage(int hp, int atk, string name)
	: Player(hp, atk, name)
{
};

Mage::~Mage()
{
};

void Mage::Attack(shared_ptr<Creature> other)
{
	if (IsDead()) return;

	cout << _name << " Mage Attack" << endl;
	other->TakeDamage(_atk, shared_from_this());
};