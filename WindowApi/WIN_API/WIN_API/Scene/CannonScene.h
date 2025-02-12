#pragma once

class Cannon;

class CannonScene: public Scene
{
	enum CannonTurn
	{
		ONE, // 0
		TWO, // 1

		TURN_COUNT // 2
	};

public:
	CannonScene();
	~CannonScene();

	void Update() override;
	void Render(HDC hdc) override;

	// Cannon들이 Fire했을 때 이 함수 호출
	void NextTurn()
	{
		// 왜 인트형으로 바꿔주느냐?
		// => 연산을 용이하게, 순차적인 처리나 순환을 간단히, 비교가 직관적
		int temp = static_cast<int>(_curTurn);
		temp++; // 턴 증가
		temp %= CannonTurn::TURN_COUNT; // 범위 내에서 순환 (0, 1)
		_curTurn = static_cast<CannonTurn>(temp); // temp를 CannonTurn enum으로 변환

		_timeElipse = 0.0f;
	}

private:
	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;

	CannonTurn _curTurn = CannonTurn::ONE;

	float _timeElipse = 0.0f;
	float _delay = 1.0f;
};

