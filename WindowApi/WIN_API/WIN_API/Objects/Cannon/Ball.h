#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _circle->SetCenter(pos); } // ��ġ����
	Vector GetPos() { return _circle->GetCenter(); }

	void SetActive(bool b) { _isActive = b; }
	bool GetActive() { return _isActive; }

	shared_ptr<CircleCollider> GetCollider() { return _circle; }

	void Fire(Vector dir);
	void AddVector(Vector v); // ���⺤��


private:
	shared_ptr<CircleCollider> _circle;

	float _ballSpeed = 3.0f;
	Vector _dir;
	bool _isActive = false;
};

