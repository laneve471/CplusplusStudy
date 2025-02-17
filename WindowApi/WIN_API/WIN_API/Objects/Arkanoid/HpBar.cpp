#include "framework.h"
#include "HpBar.h"

#include "Map.h"

HpBar::HpBar(Vector center, Vector size)
	: RectCollider(center, size)
{
	_value = make_shared<RectCollider>(center, size);
	_redBrush = CreateSolidBrush(RED);
	_defaultBrush = CreateSolidBrush(WHITE);
}

HpBar::~HpBar()
{
	DeleteObject(_redBrush);
	DeleteObject(_defaultBrush);
}

void HpBar::Update()
{
	RectCollider::Update();
	_value->Update();
}

void HpBar::Render(HDC hdc)
{
	RectCollider::Render(hdc);

	SelectObject(hdc, _redBrush);
	_value->Render(hdc);
	SelectObject(hdc, _defaultBrush);
}

void HpBar::SetValue(float value)
{
	_value->SetSize(Vector(GetSize().x * value, GetSize().y));
	
	float centerX = Left() + _value->GetHalfSize().x;
	float centerY = GetCenter().y;
	_value->SetCenter(Vector(centerX, centerY));
}