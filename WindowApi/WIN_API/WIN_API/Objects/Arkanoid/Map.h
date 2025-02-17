#pragma once

class Brick;
class Vaus;
class ArkaBall;
class Item;

class Map
{
public:
	Map();
	~Map();

	void Init(shared_ptr<Vaus> vaus);

	void Update();
	void Render(HDC hdc);

	void ReflectionByBrick(shared_ptr<ArkaBall> ball);
	void GetItems(shared_ptr<Vaus> vaus);
	bool IsClear();

	void SetCount(int n) { count = n; }

private:

	vector<vector<pair<shared_ptr<Brick>, shared_ptr<Item>>>> _bricksWithItems;

	HPEN _pen;

	int _countX = 7;
	int _countY = 4;
	int count = 3;
};