#include "pch.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>

//#include "Creature/Creature.h"
//#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Archer.h"
#include "Creature/Mage.h"
#include "Creature/Goblin.h"
#include "Creature/Boss.h"

bool IsAllDead(Creature* arr[], int size)
{
	bool allDead = true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i]->IsDead() == false)
			return false;
	}
	return allDead;
}

bool Compare (const Creature* a, const Creature* b)
{
	return ((Player*)a)->GetDamageSum() <= ((Player*)b)->GetDamageSum();
}

int main()
{
	Creature* players[10] = {};

	//int choice = 0;
	//cin >> choice;

	for (int i = 0;i < 10;i++)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));

		int randomValue = std::rand() % 3;

		switch (randomValue)
		{
		case 0:
		{
			players[i] = new Knight(100, 5, "Knight");
			break;
		}
		case 1:
		{
			players[i] = new Archer(550, 2, "Archer");
			break;
		}
		case 2:
		{
			players[i] = new Mage(101, 13, "asdasd");
			break;
		}

		default:
			players[i] = new Knight(100, 5, "Knight");
			break;
		}
	}
	
	Creature* boss = new Boss;


	while (true)
	{
		if (IsAllDead(players, 10) || boss->IsDead())
			break;

		//std::sort(players, players + 10, [](const Creature* a, const Creature* b)
			//{return ((Player*)a)->GetDamageSum() > ((Player*)b)->GetDamageSum(); });

		for (int i = 0; i < 10; i++)
		{
			if(!players[i]->IsDead())
				players[i]->Attack(boss);
		}

		if (Boss* boss_D = dynamic_cast<Boss*>(boss))
			if (!boss_D->IsDead())
				boss_D->Attack();
	}

	if (boss->IsDead())
	{
		if(Boss* boss_D = dynamic_cast<Boss*>(boss))
			boss_D->DeadSound();
	}

	for (int i = 0; i < 10; i++)
	{
		delete players[i];
	}

	delete boss;

	return 0;
}