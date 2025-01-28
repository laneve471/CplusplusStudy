#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

// unordered_map : 해쉬 테이블
// 해싱 :
// 체이닝 :
// Key - Value가 쌍으로 된 원소로 이루어진 표
// => 해싱을 이용하여 탐색시간이 '상수', 삽입, 삭제 (상수)
// ==> Key값으로 탐색에 용이하다
// ===> 게임, 넌클러스티드 인덱스

// map: 자가균형이진탐색트리, 레드블랙트리 
// Key - Value가 쌍으로 된 원소로 이루어진 이진탐색트리
// => 이진탐색을 활용하여 탐색, 삽입, 삭제 시간이 'log N'
// ==> Key값으로 탐색에 용이하다.
// ===> Database 기본key
// 

class Player
{
public:
	Player() {}
	Player(int id) : _id(id) {}

	int _id;
};
int main()
{
	/*
	// Player를 ID로 구분해서 넣는 작업
	vector<Player> players;

	for (int i = 0; i < 1000; i++)
	{
		players.push_back(i + 1);
	}

	// id가 500인 플레이어를 찾고 싶다. 
	//players[499];
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]._id == 500)
		{
			// 찾음
		}
	}
	*/ //=> vector인 경우 탐색 시간 : 시간 복잡도(N)

	/*
	unordered_map<int, Player> um;

	for (int i = 0; i < 1000; i++)
	{
		um[i + 1] = Player(i);
		// pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		// auto result = um.insert(pair);
	}
	*/

	map<int, Player> m;

	m.erase(1);

	for (int i = 0; i < 1000; i++)
	{
		m[i + 1] = Player(i);
		// pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		// auto result = um.insert(pair);
	}

	map<int, Player>::iterator m_iter;

	for (m_iter = m.begin(); m_iter != m.end(); m_iter++)
	{
		pair<int, Player> p = *m_iter;
		cout << p.first << endl;
	}
	return 0;
}