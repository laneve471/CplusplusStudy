#pragma once

#include "Player.h"

class Mage : public Player, public enable_shared_from_this<Mage>
{
public:
	Mage(int hp, int atk, string name);
	~Mage();

	virtual void Attack(shared_ptr<Creature> other) override;

private:
};