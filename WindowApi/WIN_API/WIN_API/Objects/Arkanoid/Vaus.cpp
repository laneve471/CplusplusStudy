#include "framework.h"
#include "Vaus.h"
#include "ArkaBall.h"

Vaus::Vaus()
	: RectCollider(Vector(700, 600), Vector(60, 15))
{
}

Vaus::~Vaus()
{
}

void Vaus::Init()
{
	_balls.clear();

	for (int i = 0; i < 2; i++)
	{
		auto ball = make_shared<ArkaBall>(shared_from_this());
		ball->SetActive(false);
		ball->SetFired(false);
		
		_balls.push_back(ball);
	}

	_balls[0]->_isActive = true;

	_hp = 1.0f;
}

void Vaus::Update()
{
	RectCollider::Update();

	for (auto& ball : _balls)
	{
		ball->Update();
	}

	IsFall();
	LoseLife();
}

void Vaus::Render(HDC hdc)
{
	RectCollider::Render(hdc);

	for (auto& ball : _balls)
	{
		ball->Render(hdc);
	}
}

void Vaus::Input()
{
	_delayTime += 0.1f;

	if (GetKeyState('A') & 0x8000)
	{
		if (GetCenter().x - GetHalfSize().x > ALKA_MAP_LEFT)
			SetCenter(GetCenter() + Vector(-1, 0) * _speed);
	}

	if (GetKeyState('D') & 0x8000)
	{
		if (GetCenter().x + GetHalfSize().x < ALKA_MAP_RIGHT)
			SetCenter(GetCenter() + Vector(1, 0) * _speed);
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (_delayTime > 3.0f)
		{
			_delayTime = 0.0f;

			auto ballIter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<ArkaBall> a)-> bool
				{
					if (a->GetFired())
						return false;
					return true;
				});

			if (ballIter != _balls.end())
				(*ballIter)->Fire();
		}
	}
}

void Vaus::Reset()
{
	_balls[0]->SetActive(true);
	SetCenter(Vector(700, 600));
}

void Vaus::IsFall()
{
	for (auto& ball : _balls)
	{
		if (!ball->GetActive())
			continue;

		if (ball->GetCenter().y + ball->GetRadius() >= WIN_HEIGHT)
		{
			ball->Reset();
		}
	}
}

void Vaus::LoseLife()
{
	bool allBallsInactive = true;

	for (auto& ball : _balls)
	{
		if (ball->_isActive)
		{
			allBallsInactive = false;
			break;
		}
	}

	if (allBallsInactive)
	{
		_hp -= 0.2f;

		Reset();
	}
}

void Vaus::TwoBall_Skill()
{
	auto iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<ArkaBall> ball)->bool
		{
			if (ball->GetActive() == false)
				return true;
			return false;
		});

	if (iter != _balls.end())
	{
		(*iter)->SetActive(true);
		(*iter)->Fire();
	}
}
