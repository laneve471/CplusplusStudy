#pragma once

class Brick;
class Vaus;
class ArkaBall;

class Map
{
public:
	Map();
	~Map();

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<Brick>>> GetBricks() { return _bricks; }
	void SetCount(int n) { count = n; }

private:
	vector<vector<shared_ptr<Brick>>> _bricks;

	HPEN _pen;

	int _countX = 7;
	int _countY = 4;
	int count = 3;
};