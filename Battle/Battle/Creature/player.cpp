#include "pch.h"

#include "Creature.h"
#include "Player.h"

Player::Player(int hp, int atk, string name)
	:Creature(hp, atk), _damageSum(10)
{
	_name = name;
}

Player::~Player() {}

int& Player::GetDamageSum() { return _damageSum; }