#include "framework.h"
#include "ArkaBall.h"
#include "Brick.h"
#include "Vaus.h"

ArkaBall::ArkaBall()
	: CircleCollider(Vector(700, 550), 10)
{
	_brush = CreateSolidBrush(WHITE);
}

ArkaBall::~ArkaBall()
{
}

void ArkaBall::Update()
{
	CircleCollider::Update();
	SetCenter(GetCenter() + _dir * 3.0f);
}

void ArkaBall::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	CircleCollider::Render(hdc);
}

void ArkaBall::Fire()
{
	if (!isActive)
	{
		isActive = true;
		_dir = Vector(0, -1);
	}
}

void ArkaBall::ReflectByBrick(shared_ptr<Brick>& brick)
{
	if (IsCollision(brick) && brick->isActive == true)
	{
		brick->isActive = false;

		int left = brick->Left();
		int right = brick->Right();
		int top = brick->Top();
		int bottom = brick->Bottom();
		
		/*Vector center = GetCenter();
		float radius = GetRadius();

		if (center.y >= top && center.y <= bottom)
		{
			_dir.x *= -1;
		}
		else
		{
			_dir.y *= -1;
		}*/

		// 외적 사용
		Vector rightV= Vector(1, 0);
		Vector dir1 = Vector(right, top) - brick->GetCenter();
		Vector dir2 = GetCenter() - brick->GetCenter();
		dir1.Normalize(); dir2.Normalize();
		float a = rightV.Cross(dir1);
		float b = rightV.Cross(dir2);

		if (b <= a || b >= -a)
			_dir.y *= -1;
		else
			_dir.x *= -1;
	}
}

void ArkaBall::ReflectByVaus(shared_ptr<Vaus> vaus)
{
	if (IsCollision(vaus))
	{
		Vector dir = GetCenter() - vaus->GetCenter();
		_dir = dir.NormalVector();
	}
}

void ArkaBall::ReflectByWall()
{
	Vector center = GetCenter();
	float radius = GetRadius();

	if (center.x - radius <= 400 || center.x + radius >= 1000)
	{
		_dir.x *= -1;
	}

	if (center.y - radius <= 100)
	{
		_dir.y *= -1;
	}
}
