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
	else //��ǻ�Ͱ� ū ���
	{
		cout << "you lose" << endl;
	}
}

int main()
{
	//���ڿ� x -> char Array
	// [A][B][][]

	char Type[4][3] = {
		"��", // \n�����Ǿ��פ��°���. ���ڿ� �Է½� ����Ʈ �߰�!
		"��",
		"��",
		"��"
	};
	//���ڿ��� \0 �� ���� ����, �����ٴ� �ǹ�. (C���� ���ڿ��� ���������ʾƼ� �߻��� �̽�~)
	//��� �ƴϸ� �� ���� �� �̷��͵� �� ����
	//const char Temp[3] = "AB"; //const �ȹٲٰٴٰ� ����. 
	//Temp[0] = 'A';
	//Temp[1] = 'B';
	//Temp[2] = '\0';

	//cout << Temp << endl;

	return 0;
}