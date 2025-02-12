#include "framework.h"
#include "Collider.h"

Collider::Collider(Vector center)
	: _center(center)
{
	_pens.push_back(CreatePen(1, 3, BLACK));
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
	//_pens.push_back(CreatePen(1, 3, BLUE));
}

Collider::~Collider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}