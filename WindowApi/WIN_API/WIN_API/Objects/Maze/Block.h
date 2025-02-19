#pragma once

class Block : public RectCollider
{
public:
	enum Type
	{
		NONE,
		ABLE,
		BLOCKED,
		PLAYER,

		TYPE_COUNT
	};

	Block();
	~Block();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	Block::Type GetBlockType() { return _curType; }
	void SetType(Block::Type type) { _curType = type; }

private:
	vector<HBRUSH> _brushes;

	Block::Type _curType = Type::NONE;
};

