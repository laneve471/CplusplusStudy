#include "framework.h"
#include "Player.h"

#include "Maze.h"
#include "Block.h"

Player::Player(shared_ptr<Maze> maze)
	: _maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);

	//RightHand();
	//BFS(_maze.lock()->StartPos());
	DFS(_maze.lock()->StartPos());
}

Player::~Player()
{
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		return;
	}

	_delayTime += 0.5f;
	if (_delayTime > 1.0f)
	{
		_delayTime = 0.0f;

		_maze.lock()->SetBlockType(_pos, Block::Type::FOOTPRINT);
		_pos = _path[_pathIndex];

		_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);

		_pathIndex++;
	}
}

void Player::RightHand()
{
	shared_ptr<Maze> maze = _maze.lock();

	Vector pos = maze->StartPos();
	Vector endPos = maze->EndPos();

	int curDir = Direction::UP;

	while (true)
	{
		if (pos == endPos)
		{
			_path.push_back(pos);
			break;
		}

		int newDir = (curDir - 1 + DIR_COUNT) % DIR_COUNT;
		Vector oldVector = pos + frontPos[curDir]; // ���� �ٶ󺸰� �ִ� �������� �� ĭ +
		Vector newVector = pos + frontPos[newDir]; // ������ �������� �� ĭ +

		// ���������� �� �� ���� ��� ���������� ������ �ٲٰ� �� �������� �̵�
		if (CanGo(newVector))
		{
			curDir = newDir;
			pos = newVector;
			_path.push_back(pos);
		}

		// �������� �����ְ� �� ������ �շ����� ��� �״�� �̵�
		else if (CanGo(oldVector))
		{
			pos = oldVector;
			_path.push_back(pos);
		}

		// �� �� ����������
		else
		{
			curDir = (curDir + 1 + DIR_COUNT) % DIR_COUNT;
		}
	}

	stack<Vector> s;
	// ����Ŭ ó��

	for (int i = 0; i < _path.size() - 1; i++)
	{
		maze->SetBlockType(_path[i], Block::SEARCHED);
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
			s.push(_path[i]);
	}

	_path.clear();
	while (true)
	{
		if (s.empty() == true)
			break;

		Vector top = s.top();
		_path.push_back(top);
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());
}

bool Player::CanGo(Vector pos)
{
	if (_maze.lock()->GetBlockType(pos) == Block::Type::BLOCKED)
		return false;
	return true;
}

void Player::BFS(Vector start)
{
	_visited = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));

	queue<Vector> q;
	q.push(start);
	_visited[start.y][start.x] = true;
	_parent[start.y][start.x] = start;

	while (true)
	{
		Vector here = q.front();
		q.pop();

		// ���� �����̸� �ݺ� ����
		if (here == _maze.lock()->EndPos())
			break;

		for (int i = 0; i < 4; i++)
		{
			Vector there = here + frontPos[i];

			// here�� there�� ������?
			if (here == there)
				continue;

			// there�� �� �� �ִ� ���ΰ�?
			if (!CanGo(there))
				continue;

			// there�� �湮�� �� �ִ°�?
			if (_visited[there.y][there.x])
				continue;

			q.push(there);
			_visited[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
			_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);
		}
	}

	// ������ �������Լ� �߰ߵǾ����� Ÿ�� �ö󰡱�
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);

	while (true)
	{
		// parent�� start �����̸� �׸�
		if (vertex == start)
			break;

		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}
	reverse(_path.begin(), _path.end());
}

void Player::DFS(Vector here)
{
	_visited[here.y][here.x] = true;
	_path.push_back(here);

	for (int i = 0; i < 4; i++)
	{
		// ���� �����̸� �ݺ� ����
		if (here == _maze.lock()->EndPos())
			break;

		Vector there = here + frontPos[i];

		// here�� there�� ������?
		if (here == there)
			continue;

		// there�� �� �� �ִ� ���ΰ�?
		if (!CanGo(there))
			continue;

		// there�� �湮�� �� �ִ°�?
		if (_visited[there.y][there.x])
			continue;

		_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);
		DFS(there);
	}
}
