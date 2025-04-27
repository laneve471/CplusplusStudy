#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// 1. �׷����� ����
// - ������ �������� �̷���� �ڷᱸ��
//		- ����(vertex) : �����͸� ��Ÿ���� ���
//		- ����(edge) : ��� ���� ���質 ������ ��Ÿ���� ��
//		- ���� : �ϳ��� ������ ����(adjacent)�� ������ ��
// - ���� / ������ / ����ġ / ��ȯ(����Ŭ) / ���ȯ
//		- ����ġ �׷��� : ������ ����ġ �Ҵ�
// - ���� �׷��� : ��� ������ ���� ���� (���� �� �ִ�)
//
// 2. ���� �� ����ߴ°�
// - �����ϸ�Ʈ ���Ϸ�
// - �����������ũ �ٸ� �ǳʱ� ����
//		- 7���� �ٸ��� �� ������ �ǳ� ��� �ٸ��� �ǳ� �� �ִ°�
// 
// 3. Ȱ��
// - �ִ� ��� Ž��
// - ��Ʈ��ũ ���� ����
// - ����, ����ö �뼱��
// 
// 4. �׷��� ��ȸ
// - DFS (Deep First Search) : ���� �켱 Ž��
//		- ���� ������ �̿��Ͽ� ��ȸ
//		- ������������ Ȱ�� -> ����Լ�
//		- ��ã�� ���� ��� ���� -> ���� �� ã��
// 
// - BFS (Breadth First Search) : ���� �켱 Ž��
//		- ť �̿��Ͽ� ��ȸ
//		- ���� �������ִ��� �� �� ����
//		- �ִ� �Ÿ��� ã�ƾ� �� ��


// ��������Ʈ : Ž�� O(N)
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

// ������� : �����͸� ���� �Դ� ��� Ž���ϴ� ���� ����� �ð�
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

	// ����� : �׷��� A�� ��ġ��� A�� ����
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

// ��������Ʈ

	//CreateGraph_list();

	//// 0�� 2�� ���� ������ �Ǿ��ֳ�?
	//auto iter = find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	//if (iter != adjacent_list[0].end())
	//	cout << *iter << endl;

	//if (adjacent[0][2]) // ����� �ð�
	//	cout << 1 << endl;

// BFS

	cout << endl << "BFS" << endl;

	BFS(0);

	// 0���� 6������ �Ÿ�
	// parent�� ���������� Ÿ�� ���ٺ��� �Ÿ��� ���´�.
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