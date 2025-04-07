#include <iostream>
#include <algorithm>
#define CARD_COUNT		52

using namespace std;
//[][][][][]

	//global variable
int Deck[CARD_COUNT] = { 0, };

void Initialize()
{
	srand((unsigned int)time(NULL));
	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index;
	}
}

void Shuffle()
{
	int Temp = 0;
	for (int Count = 0; Count < CARD_COUNT * 1000; Count++)
	{
		int First = rand() % CARD_COUNT;
		int Second = rand() % CARD_COUNT;
		Temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = Temp;
	}
}
int PrintCard(int CardRealNumber)
{
	//Type
	//Heart, Clover, Space, Diamond
	int CardType = Deck[0] / 13;
	int CardNumber = Deck[0] % 13 + 1;
	int Score = CardNumber;

	if (CardType == 0)
	{
		cout << "Heart" << endl;
	}
	else if (CardType == 1)
	{
		cout << "Clover" << endl;
	}
	else if (CardType == 2)
	{
		cout << "Space" << endl;
	}
	else // (CardType ==3)
	{
		cout << "Diamond";
	}

	if (CardNumber == 1)
	{
		cout << "A" << CardNumber << endl;
	}
	else if (CardNumber == 11)
	{
		cout << "J" << endl;
		Score = 10;
	}
	else if (CardNumber == 12)
	{
		cout << "Q" << endl;
		Score = 10;
	}
	else if (CardNumber == 13)
	{
		cout << "K" << endl;
		Score = 10;
	}
	else
	{
		cout << " " << endl;
	}
	return Score;

}
void Print()
{
	int ComputerScore = 0;
	int PlayerScore = 0;
	cout << "Computer" << endl;
	ComputerScore = ComputerScore + PrintCard(Deck[0]);
	ComputerScore += PrintCard(Deck[1]);
	cout << "ComputerScore : " << ComputerScore << endl;

	cout << "============\n\n" << endl;

	cout << "Player" << endl;
	cout << "PlayerScore : " << PlayerScore << endl;
	ComputerScore += PrintCard(Deck[2]);
	ComputerScore += PrintCard(Deck[3]);

	if (ComputerScore > 21)
	{
		cout << "you win" << endl;
	}
	else if (PlayerScore > 21)
	{
		cout << "you lose" << endl;
	}
	else if (PlayerScore >= ComputerScore)
	{
		cout << "you lose" << endl;
	}
	else //컴퓨터가 큰 경우
	{
		cout << "you lose" << endl;
	}
}

int main()
{
	//문자열 x -> char Array
	// [A][B][][]

	char Type[4][3] = {
		"♥", // \n생략되어잉ㅆ는거임. 문자열 입력시 바이트 추가!
		"◆",
		"♣",
		"♠"
	};
	//문자열에 \0 에 들어가면 없다, 끝났다는 의미. (C언어에서 문자열이 존재하지않아서 발생한 이슈~)
	//영어가 아니면 다 문자 ★ 이런것도 다 문자
	//const char Temp[3] = "AB"; //const 안바꾸겟다고 강제. 
	//Temp[0] = 'A';
	//Temp[1] = 'B';
	//Temp[2] = '\0';

	//cout << Temp << endl;

	return 0;
}