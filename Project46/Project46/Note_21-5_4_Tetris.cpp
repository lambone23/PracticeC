#include <iostream>
using namespace std;

void FnApplyGravity(char SpaceShip[4][3])
{
	for (int X = 0; X < 3; X++)
	{// 낙하를 해야하는 총 3개의 줄

		for (int RepeatCnt = 0; RepeatCnt < 3; RepeatCnt++)
		{// 최소 3번은 낙하작업을 반복해야 함. (Y < 4)이므로.

			for (int Y = 3; Y > 0; Y--)
			{// 한단계씩 아래로 낙하

				if (SpaceShip[Y][X] == '_')
				{
					SpaceShip[Y][X] = SpaceShip[Y - 1][X];
					SpaceShip[Y - 1][X] = '_';
				}
			}
		}
	}
}

void FnPrint(char SpaceShip[4][3])
{// 출력

	cout << endl;

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cout << SpaceShip[IdxY][IdxX];
		}

		cout << endl;
	}
}

void FnInput(char SpaceShip[4][3])
{// 입력

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cin >> SpaceShip[IdxY][IdxX];
		}
	}
}

int main()
{
	char SpaceShip[4][3] = {};

	FnInput(SpaceShip);

	FnApplyGravity(SpaceShip);

	FnPrint(SpaceShip);

	return 0;
}
