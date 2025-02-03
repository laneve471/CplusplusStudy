#pragma once
class Barrel;
class Ball;

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	//void PostInitialize(); // 후처리랬나?

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();

	shared_ptr<CircleCollider> GetCollider() { return _body; }

private:
	shared_ptr<CircleCollider>	_body;

	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;

	// 컴포넌트 패턴
	// 1. 코드의 재사용성
	// 2. 유니티 핵심요소, 언리얼 중요요소(상속, 컴포넌트)
	shared_ptr<Barrel>			_barrel;

	// 오브젝트 풀링(변식지?를 만드는 것)
	// 동적할당 커널?
	// 할당 - 해제를 최소화 하기 위해서
	// => 미리 만들어놓고 나중에 쓸 일이 없을 때 지우는 것
	UINT						_poolCount;
	vector<shared_ptr<Ball>>	_balls;
	Vector						_ballDir;
	float						_theta;

	float						_speed;	
	Vector						_gravity = Vector(0, 1);
};

