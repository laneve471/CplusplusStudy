#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp);
	~Knight();

	void PrintInfo();

public:
	int _hp = 100;
	int _attack = 10;
};

