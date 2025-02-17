#pragma once

class Item : public CircleCollider
{
public:
	Item();
	~Item();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetSkill(function<void(void)> fn) { _barSkill = fn; }
	void ActiveSkill() { if (_barSkill) { _barSkill(); } }

	bool CanFalling() { return _canFalling; }
	void SetFalling(bool canFalling) { _canFalling = canFalling; }

	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }

private:
	function<void(void)> _barSkill;

	shared_ptr<CircleCollider> _body;

	float _speed = 4.0f;

	bool _canFalling = false;
	bool _isActive = false;
};

