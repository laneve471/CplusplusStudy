#pragma once
class ArkaBall;

class Vaus : public RectCollider
{
public:
	Vaus();
	~Vaus();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void MoveLeft();
	void MoveRight();

private:
	HBRUSH _brush;
	float _speed = 10.0f;
};

