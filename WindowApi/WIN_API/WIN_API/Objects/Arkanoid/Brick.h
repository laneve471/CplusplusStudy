#pragma once

class Brick : public RectCollider
{
public:

	Brick();
	~Brick();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }

private:
	bool _isActive = false;
};