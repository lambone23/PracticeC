/*

입력 예제
0 0 0 0
0 0 1 0
1 1 1 1
1 1 1 1
0 1 0 0

출력 결과
0 0 0 0
0 0 0 0
0 0 0 0
0 0 1 0
0 1 0 0

*/


#include <iostream>
using namespace std;

void FnPrint(int PBoard[5][4])
{
	cout << endl;
	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			cout << PBoard[IdxY][IdxX] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int Board[5][4] = {};

	int Direct[3][2]
		= {
			{0, 1}, {0, 2}, {0, 3}
	};

	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			cin >> Board[IdxY][IdxX];
		}
	}

	FnPrint(Board);

	bool ChkFull = 0;

	int RemoveLineHisotry[5] = {};

	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		ChkFull = 0;

		if (Board[IdxY][0] == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				int DirectY = IdxY + Direct[i][0];
				int DirectX = Direct[i][1];

				if (Board[DirectY][DirectX] == 1)
				{
					ChkFull = 1;
				}
				else
				{
					ChkFull = 0;
					break;
				}
			}

			if (ChkFull)
			{
				RemoveLineHisotry[IdxY]++;

				for (int IdxX = 0; IdxX < 4; IdxX++)
				{
					Board[IdxY][IdxX] = 0;
				}
			}
		}
	}

	FnPrint(Board);

	for (int Idx = 1; Idx < 5; Idx++)
	{// 맨 윗줄은 꽉찬줄이어도 의미없으므로 skip

		if (RemoveLineHisotry[Idx] > 0)
		{
			int Y = Idx - 1;

			for (int IdxX = 0; IdxX < 4; IdxX++)
			{
				if ((Board[Y][IdxX] == 1) && ((Y + 1) <= 4))
				{
					Board[Y + 1][IdxX] = Board[Y][IdxX];
					Board[Y][IdxX] = 0;
				}
			}
		}
	}

	FnPrint(Board);

	return 0;
}

