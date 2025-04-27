#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// 1. 그래프의 개념
// - 정점과 간선으로 이루어진 자료구조
//		- 정점(vertex) : 데이터를 나타내는 노드
//		- 간선(edge) : 노드 간의 관계나 연결을 나타내는 선
//		- 차수 : 하나의 정점에 인접(adjacent)한 정점의 수
// - 방향 / 무방향 / 가중치 / 순환(사이클) / 비순환
//		- 가중치 그래프 : 간선에 가중치 할당
// - 완전 그래프 : 모든 정점이 서로 연결 (간선 수 최대)
//
// 2. 누가 왜 고안했는가
// - 레온하르트 오일러
// - 쾨니히스베르크 다리 건너기 문제
//		- 7개의 다리를 한 번씩만 건너 모든 다리를 건널 수 있는가
// 
// 3. 활용
// - 최단 경로 탐색
// - 네트워크 연결 문제
// - 버스, 지하철 노선도
// 
// 4. 그래프 순회
// - DFS (Deep First Search) : 깊이 우선 탐색
//		- 스택 구조를 이용하여 순회
//		- 스택프레임을 활용 -> 재귀함수
//		- 길찾기 제외 모든 문제 -> 닫힌 계 찾기
// 
// - BFS (Breadth First Search) : 넓이 우선 탐색
//		- 큐 이용하여 순회
//		- 어디와 인접해있는지 알 수 있음
//		- 최단 거리를 찾아야 할 때


// 인접리스트 : 탐색 O(N)
vector<vector<int>> adjacent_list;
void CreateGraph_list()
{
	adjacent_list.resize(7);
	adjacent_list[0] = { 0,1,2,3 };
	adjacent_list[1] = { 0,1,4 };
	adjacent_list[2] = { 0,2,5,6 };
	adjacent_list[3] = { 0,3 };
	adjacent_list[4] = { 1,4 };
	adjacent_list[5] = { 2,5 };
	adjacent_list[6] = { 2,6 };
}

// 인접행렬 : 데이터를 많이 먹는 대신 탐색하는 데에 상수의 시간
vector<vector<bool>> adjacent;

// BFS
vector<bool> discovered(7, false);
vector<int> parent;

// DFS
vector<bool> visited;

void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false)); // 7x7
	// adjacent.resize(7, vector<bool>(7, false));

	// BFS
	discovered = vector<bool>(7, false);
	parent = vector<int>(7, -1);

	// DFS
	visited = vector<bool>(7, false);

	// 양방향 : 그래프 A는 전치행렬 A와 동일
	//   0 1 2 3 4 5 6
	// 0 1 1 1 1 0 0 0
	// 1 1 1 0 0 1 0 0
	// 2 1 0 1 0 0 1 1
	// 3 1 0 0 1 0 0 0
	// 4 0 1 0 0 1 0 0
	// 5 0 0 1 0 0 1 0
	// 6 0 0 1 0 0 0 1

	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][3] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][4] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][5] = true;
	adjacent[2][6] = true;

	adjacent[3][0] = true;
	adjacent[3][3] = true;

	adjacent[4][1] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][2] = true;
	adjacent[6][6] = true;
}

void BFS(int start)
{
	discovered[start] = true;
	parent[start] = start;
	queue<int> q;
	q.push(start);

	while (true)
	{
		if (q.empty())
			break;

		int here = q.front();
		cout << here << endl;
		q.pop();

		for (int there = 0; there < adjacent.size(); there++)
		{
			if (here == there)
				continue;

			if (adjacent[here][there] == false)
				continue;

			if (discovered[there] == true)
				continue;

			q.push(there);
			discovered[there] = true;
			parent[there] = here;
		}
	}
}

void DFS(int here)
{
	visited[here] = true;
	cout << here << endl;

	for (int there = 0; there < adjacent.size(); there++)
	{
		if (here == there)
			continue;

		if (visited[there])
			continue;

		if (!adjacent[here][there])
			continue;

		DFS(there);
	}
}

int main()
{
	CreateGraph();

// 인접리스트

	//CreateGraph_list();

	//// 0과 2가 현재 연결이 되어있냐?
	//auto iter = find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	//if (iter != adjacent_list[0].end())
	//	cout << *iter << endl;

	//if (adjacent[0][2]) // 상수의 시간
	//	cout << 1 << endl;

// BFS

	cout << endl << "BFS" << endl;

	BFS(0);

	// 0에서 6까지의 거리
	// parent를 시작점까지 타고 들어가다보면 거리가 나온다.
	int distance = 0;
	int tempParent = 6;
	while (true)
	{
		tempParent = parent[tempParent];
		distance++;

		if (tempParent == parent[tempParent])
			break;
	}

	cout << "distance : " << distance << endl;


// DFS

	cout << endl << "DFS" << endl;

	DFS(0);

	return 0;
}