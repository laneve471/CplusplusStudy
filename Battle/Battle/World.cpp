#include "pch.h"

#include "Creature/Boss.h"
#include "Creature/Knight.h"
#include "Creature/Archer.h"
#include "Creature/Mage.h"
#include "World.h"

World::World()
{
	_boss = make_shared<Boss>();

	for (int i = 0; i < 10; i++)
	{
		int randNum = rand() % 3;

		if (randNum == 0)
		{
			_players.push_back(make_shared<Knight>(100, 5, "Knight"));
		}
		else if (randNum == 1)
		{
			_players.push_back(make_shared<Archer>(50, 10, "Archer"));
		}
		else
		{
			_players.push_back(make_shared<Mage>(30, 20, "Mage"));
		}
	}
}

World::~World()
{
}

void World::Update()
{
	for (auto player : _players)
	{
		player->Attack(_boss);
	}

	shared_ptr<Boss> boss = dynamic_pointer_cast<Boss>(_boss);
	if (boss != nullptr)
	{
		boss->AttackAggro();
	}
}

bool World::End()
{
	if (_boss->IsDead())
	{
		cout << "보스를 해치웠습니다!" << endl;
		return true;
	}

	for (auto player : _players)
	{
		if (!player->IsDead())
		{
			return false;
		}
	}
	cout << "전멸했습니다..." << endl;
	return true;
}
