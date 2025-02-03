#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_rect = make_shared<RectCollider>(Vector(100,100), Vector(70,30));
	_circle = make_shared<CircleCollider>(Vector(500, 500), 10);

	//HPEN pen = CreatePen(1, 1, RGB(100, 1, 1)); // new로 할 수 없음

	_pens.push_back(CreatePen(1, 3, RGB(100, 100, 80)));
	_pens.push_back(CreatePen(1, 3, RGB(30, 30, 160)));

	_brushes.push_back(CreateSolidBrush(RGB(164, 119, 100)));
	_brushes.push_back(CreateSolidBrush(RGB(50, 150, 255)));

}

PaintScene::~PaintScene()
{
	for (auto& pen : _pens)
		DeleteObject(pen);

	for (auto& brush : _brushes)
		DeleteObject(brush);
}

void PaintScene::Update()
{
	// rect는 t가 0.03인 상태로 선형보간
	Vector rectCenter = _rect->GetCenter();
	rectCenter = LERP(rectCenter, mousePos, 0.03f);
	_rect->SetCenter(rectCenter);

	_rect->Update();
	_circle->Update();
}

void PaintScene::Render(HDC hdc)
{
	_rect->Render(hdc);
	_circle->Render(hdc);
}
