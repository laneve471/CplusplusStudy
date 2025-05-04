#pragma once

#include "Maze.h"

class Maze;

class Player
{
	enum Direction // 우수법
	{
		UP,
		LEFT,
		BOTTOM,
		DOWN,

		DIR_COUNT = 4
	};

	Vector frontPos[4] =
	{
		{0,-1}, // UP
		{-1, 0}, // LEFT
		{0, 1}, // BOTTOM
		{1, 0}, // RIGHT
	};

public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();

	void RightHand();

	bool CanGo(Vector pos);

	void BFS(Vector start); // 최단 거리(최소 간선의 개수)
	void DFS(Vector start);

private:
	weak_ptr<Maze> _maze;

	Vector _pos = { 1,1 };
	vector<Vector> _path;

	int _pathIndex = 0;
	float _delayTime = 0.0f;

	// RightHand (우수법)
	Vector _dir = Vector(0, -1);

	// BFS
	vector<vector<bool>> _visited = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	vector<vector<Vector>> _parent;
};

