#pragma once

class Barrel;
class Ball;

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire(function<void(void)> fn);

	shared_ptr<CircleCollider> GetCollider() { return _body; }
	vector<shared_ptr<Ball>> GetBalls() { return _balls; }

	bool IsCollision(shared_ptr<Ball> ball);

private:
	shared_ptr<CircleCollider>	_body;
	// 컴포넌트 패턴
	// 1. 코드의 재사용성
	// 2. 유니티 핵심요소, 언리얼 중요요소(상속, 컴포넌트)
	shared_ptr<Barrel>			_barrel;

	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;

	// 오브젝트 풀링(변수지를 만드는 것)
	// 동적할당 커널
	// 할당 - 해제를 최소화 하기 위해서
	// => 미리 만들어놓고 나중에 쓸 일이 없을 때 지우는 것
	UINT						_poolCount;
	vector<shared_ptr<Ball>>	_balls;

	float						_speed;
	bool _isActive = true;
};

