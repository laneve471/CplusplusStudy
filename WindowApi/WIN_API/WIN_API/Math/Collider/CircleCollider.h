#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>, public Collider
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update();
	void Render(HDC hdc);

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }

	bool IsCollision(const Vector& pos);
	bool IsCollision(shared_ptr<Collider> other);
	
private:
	float				_radius;
};