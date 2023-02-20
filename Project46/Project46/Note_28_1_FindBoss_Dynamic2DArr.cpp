/*

입력 예제
7
0 0 0 0 1 0 1
0 0 0 0 0 1 0
1 1 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

출력 결과
boss:2
under:4 6

*/


#include <iostream>
using namespace std;

int main()
{
	int Cnt = 0;

	cin >> Cnt;

	int** InArr = new int* [Cnt];

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		InArr[Idx] = new int[Cnt];
	}

	for (int IdxY = 0; IdxY < Cnt; IdxY++)
	{
		for (int IdxX = 0; IdxX < Cnt; IdxX++)
		{
			cin >> InArr[IdxY][IdxX];
		}
	}

	int BossIdx = 0;
	int* Unders = new int[Cnt] {};

	int FlagBossFind = 0;

	for (int IdxX = 0; IdxX < Cnt; IdxX++)
	{
		if (InArr[0][IdxX] == 0)
		{
			FlagBossFind = 0;

			for (int IdxY = 0; IdxY < Cnt; IdxY++)
			{
				if ((InArr[IdxY][IdxX] == 0) && (InArr[IdxX][0] == 1))
				{
					FlagBossFind = 1;
				}
				else
				{
					FlagBossFind = 0;
					break;
				}
			}

			if (FlagBossFind)
			{
				BossIdx = IdxX;
			}
		}
		else if (InArr[0][IdxX] == 1)
		{
			++(Unders[IdxX]);
		}
	}

	cout << "boss:" << BossIdx << endl;
	cout << "under:";

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		if (Unders[Idx] > 0)
		{
			cout << Idx << " ";
		}
	}

	delete[] Unders;

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		delete[]  InArr[Idx];
	}

	delete[] InArr;

	return 0;
}
