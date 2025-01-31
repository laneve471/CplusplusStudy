#include "pch.h"

#include "Player.h"

class Archer : public Player
{
public:
	Archer(int hp, int atk, string name);
	~Archer();

	void Attack(Creature* other) override;

private:
};