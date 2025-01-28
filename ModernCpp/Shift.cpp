#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

// 좌측값(l-value), 우측값(r-value)

// l-value
// - 수정 가능
// - 대표적인 예) 참조
// 
// r-value
// l-value 아닌 애들
// - 대표적인 예) const, 상수

// Shift : 이동, 이사
// (자료형)&& : 우측값 참조 => C++11
class Pet
{

};

class Player
{
public:
	Player() { pet = new Pet(); }
	Player(int hp) { pet = new Pet(); }
	Player(const Player& other)
	{
		this->pet = new Pet(*other.pet); // 깊은 복사
	}

	// 우측값 참조
	// 1. 원본에 접근 가능
	// 2. other는 문법적으로 우측값 참조 => 껍데기만 남기겠다
	// -> 매개변수 other는 임시값처럼 사용하겠다
	Player(Player&& other) noexcept // 이동생성자
	{
		cout << "이동생성자 호출" << endl;
		this->pet = other.pet;
		other.pet = nullptr;
	}
	~Player()
	{
		if (pet != nullptr)
			delete pet;
	}

private:
	Pet* pet;
};

int main()
{
	const int temp = 1;

	// player1에서 player2로 이사
	Player* player1 = new Player();
	Player* player2 = new Player(static_cast<Player&&>(*player1)); // 이동 개념 : 이사
	// Player* player2 = new Player(std::move(*player1));

	// 임시값 참조 반환은 위험 -> 우측값 참조는 가능

	unique_ptr<Player> up = make_unique<Player>();
	unique_ptr<Player> up2 = std::move(up);

	//vector<Player> players;
	//players.emplace_back(Player()); // players[0]

	delete player2;
	delete player1;

	//temp = 5;
	return 0;

}