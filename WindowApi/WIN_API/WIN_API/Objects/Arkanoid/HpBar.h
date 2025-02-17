#pragma once

class HpBar : public RectCollider
{
public:
	HpBar(Vector center, Vector size);
	~HpBar();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetValue(float value);

private:
	shared_ptr<RectCollider> _value;

	HBRUSH _redBrush;
	HBRUSH _defaultBrush;
};

