#pragma once

class Item;

class Brick : public RectCollider
{
public:

	Brick();
	~Brick();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	bool isActive = true;

private:
	HBRUSH _brush;

	shared_ptr<Item> _item;
};