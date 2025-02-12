#include "pch.h"
#include "Boss.h"
#include "Player.h"

Boss::Boss()
	: Monster(300, 5)
{
}

Boss::~Boss()
{
}

void Boss::Attack(shared_ptr<Creature> other)
{
	if (IsDead()) return;

	cout << _name << " Boss Attack!!!" << endl;
	other->TakeDamage(_atk);
}

void Boss::AttackAggro() // 상위 누적 데미지 4명 공격
{
	if (IsDead()) return;

	// 4명 이하인 경우
	if (_aggroTable.size() <= 4)
	{
		for (auto info : _aggroTable)
		{
			Attack(info.player.lock());
		}
		return;
	}

	// 4명 초과인 경우 상위 4명 찾기
	partial_sort(_aggroTable.begin(), _aggroTable.begin() + 4, _aggroTable.end());
	for (int i = 0; i < 4; i++)
	{
		Attack(_aggroTable[i].player.lock());
	}

	// 플레이어가 사망시 삭제
	auto removeIter = remove_if(_aggroTable.begin(), _aggroTable.end(), [](const PlayerInfo& info)->bool
		{
			if (info.player.lock()->IsDead())
				return true;
			return false;
		});

	_aggroTable.erase(removeIter, _aggroTable.end());
}


void Boss::TakeDamage(int damage, shared_ptr<Creature> attacker)
{
	// 공격을 받았을 경우
	// 플레이어가 맞는지 확인
	shared_ptr<Player> player = dynamic_pointer_cast<Player>(attacker);
	if (player == nullptr)
		return;

	Creature::TakeDamage(damage);

	// aggroTable에 attacker가 있는가?
	auto iter = find_if(_aggroTable.begin(), _aggroTable.end(), [player](const PlayerInfo& info)->bool
		{
			if (info.player.lock() == player)
				return true;
			return false;
		});

	// 없을 경우 (처음 공격)
	if (iter == _aggroTable.end())
	{
		PlayerInfo info;
		info.player = player;
		info.totalDamage = damage;

		_aggroTable.push_back(info);
	}
	// 있을 경우
	else
		iter->totalDamage += damage;
}