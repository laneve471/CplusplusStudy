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
	// ������Ʈ ����
	// 1. �ڵ��� ���뼺
	// 2. ����Ƽ �ٽɿ��, �𸮾� �߿���(���, ������Ʈ)
	shared_ptr<Barrel>			_barrel;

	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;

	// ������Ʈ Ǯ��(�������� ����� ��)
	// �����Ҵ� Ŀ��
	// �Ҵ� - ������ �ּ�ȭ �ϱ� ���ؼ�
	// => �̸� �������� ���߿� �� ���� ���� �� ����� ��
	UINT						_poolCount;
	vector<shared_ptr<Ball>>	_balls;

	float						_speed;
	bool _isActive = true;
};

