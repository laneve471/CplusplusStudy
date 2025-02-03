#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle = make_shared<CircleCollider>(Vector(450, 500), 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 60);

	_rect = make_shared<RectCollider>(Vector(800, 500), Vector(130, 130));
	_movingRect = make_shared<RectCollider>(Vector(0, 0), Vector(15, 70));
}

CollisionScene::~CollisionScene()
{}


void CollisionScene::Update()
{
	//_movingCircle->SetCenter(mousePos);
	//// movingRect 움직이기, 색판정

	//if (_circle->IsCollision(_movingCircle))
	//{
	//	_circle->SetRed();
	//}
	//else
	//{
	//	_circle->SetGreen();
	//}

	//_circle->Update();
	//_movingCircle->Update();

	_movingCircle->SetCenter(mousePos);
	// movingRect 움직이기, 색판정

	if (_rect->IsCollision(_movingCircle))
	{
		_rect->SetRed();
	}
	else
	{
		_rect->SetGreen();
	}

	if (_movingCircle->IsCollision(_rect))
		_movingCircle->SetBlue();
	else
		_movingCircle->SetGreen();

	_rect->Update();
	_movingRect->Update();
}


void CollisionScene::Render(HDC hdc)
{
	_rect->Render(hdc);
	_movingCircle->Render(hdc);
}