#include "pch.h"
#include "Boss.h"
#include <algorithm>
#include <iterator>
#include "Player.h"

Boss::Boss() : Monster(50, 5) {}

Boss::Boss(int hp, int atk, string name)
	:Monster(hp, atk)
{
	SetName(name);
}

Boss::~Boss() {}

void Boss::Attack()
{
	cout << _name << " Boss Attack!!!" << endl;
	for (int i = 0; i < 4; i++)
	{
		target[i]->TakeDamage(_atk, this);
	}
}

void Boss::DeadSound()
{
	cout << "²Ù¿¡¿¢!!!" << endl;
}

void Boss::TakeDamage(int amount, Creature* attacker)
{
	_hp -= amount;
	target.push_back(attacker);
	std::sort(target.begin(), target.end(), [](const Creature* a, const Creature* b)
			{return ((Player*)a)->GetDamageSum() > ((Player*)b)->GetDamageSum(); });

	if (_hp < 0)
		_hp = 0;
}

std::vector<Creature*> Boss::GetTarget() { return target; }