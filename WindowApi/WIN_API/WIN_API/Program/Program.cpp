#include "framework.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/LineScene.h"
#include "Scene/LineCollisionScene.h"
#include "Scene/CannonScene.h"
#include "Scene/ArkanoidScene.h"
#include "Scene/MazeScene.h"

HDC Program::backBuffer = nullptr;
Program::Program()
{
	_scene = make_shared<MazeScene>();

	HDC hdc = GetDC(hWnd);

	backBuffer = CreateCompatibleDC(hdc);
	_hBitMap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBuffer, _hBitMap);
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_scene->Render(backBuffer);

	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}