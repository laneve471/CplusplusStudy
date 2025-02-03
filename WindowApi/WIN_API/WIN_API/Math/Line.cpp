#include "framework.h"
#include "Line.h"

Line::Line(Vector start, Vector end)
	: start(start), end(end)
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
	_pens.push_back(CreatePen(1, 3, BLUE));
}

Line::~Line()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);
	MoveToEx(hdc, start.x, start.y, nullptr);
	LineTo(hdc, end.x, end.y);
}

Line::HitResult Line::IsCollision(shared_ptr<Line> other)
{
	/*Vector vector1 = end - start;
	Vector vector2 = other->end - other->start;

	float c1 = vector1.Cross(other->end - start);
	float c2 = vector1.Cross(other->start - start);
	float c3 = vector2.Cross(end - other->start);
	float c4 = vector2.Cross(start - other->start);

	if (c1 * c2 < 0 && c3 * c4 < 0)
		return true;

	return false; */

	Line::HitResult hitResult; 
	Vector v1Dir = end - start;
	Vector a1 = other->start - start;
	Vector b1 = other->end - start;

	bool v1_Between = v1Dir.IsBetween(a1, b1);

	Vector v2Dir = other->end - other->start;
	Vector a2 = start - other->start;
	Vector b2 = end - other->start;

	bool v2_Between = v2Dir.IsBetween(a2, b2);

	hitResult.isCollision = v1_Between && v2_Between;
	if (hitResult.isCollision == false)
		return hitResult;

	// Ãæµ¹ÇßÀ» °æ¿ì
	// ÁÂ¿ì »ï°¢Çü ³ÐÀÌ
	float leftB = abs(v1Dir.Cross(a1));
	float rightB = abs(v1Dir.Cross(b1));

	float t = leftB / (leftB + rightB);
	hitResult.hitPoint = LERP(other->start, other->end, t);

	return hitResult;
}

/*Vector Line::IsIntersection(shared_ptr<Line> other)
{
	Vector v1 = end - start;
	Vector v2 = other->end - other->start;

	Vector a = other->start - start;
	Vector b = other->end - start;

	float crossA = v1.Cross(a);
	float crossB = v2.Cross(b);

	float t = crossA / (crossA + crossB);

	Vector result = other->start + v2 * t;

	return result;
}
*/
