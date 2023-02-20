#include <iostream>
using namespace std;

void FnApplyGravity(char SpaceShip[4][3])
{
	for (int X = 0; X < 3; X++)
	{// ���ϸ� �ؾ��ϴ� �� 3���� ��

		for (int RepeatCnt = 0; RepeatCnt < 3; RepeatCnt++)
		{// �ּ� 3���� �����۾��� �ݺ��ؾ� ��. (Y < 4)�̹Ƿ�.

			for (int Y = 3; Y > 0; Y--)
			{// �Ѵܰ辿 �Ʒ��� ����

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
{// ���

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
{// �Է�

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
