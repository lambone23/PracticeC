/*

입력 예제
6
4 T
4 F
5 E
5 F
5 A
1 C

출력 결과
1 C
4 F
4 T
5 A
5 E
5 F

*/

#include <iostream>
using namespace std;

struct Set
{
	int Value;
	char Data;
};

Set* g_InArr = nullptr;
int g_n = 0;

void FnPrint()
{
	for (int Idx = 0; Idx < g_n; Idx++)
	{
		cout << g_InArr[Idx].Value << " " << g_InArr[Idx].Data << endl;
	}
	cout << endl;
}

void FnSwap(int* PTmpIdx, int Idx1, int Idx2)
{
	Set TmpSet = g_InArr[Idx1];
	g_InArr[Idx1] = g_InArr[Idx2];
	g_InArr[Idx2] = TmpSet;

	(*PTmpIdx) = Idx2;
}

int main()
{
	// 입력
	while (true)
	{
		cin >> g_n;

		if ((1 <= g_n) && (100 >= g_n))
		{
			break;
		}
		else
		{
			cout << "(1 <= n <= 100) 입력 가능 범위" << endl;
		}
	}

	g_InArr = new Set[g_n];

	for (int Idx = 0; Idx < g_n; Idx++)
	{
		cin >> g_InArr[Idx].Value;
		cin >> g_InArr[Idx].Data;
	}
	cout << endl;


	// 처리
	if (g_n == 1)
	{
		cout << g_InArr[0].Value << " " << g_InArr[0].Data;
	}
	else
	{
		for (int Idx = 1; Idx < g_n; Idx++)
		{
			int TmpIdx = Idx;

			for (int CompIdx = Idx - 1; CompIdx >= 0; CompIdx--)
			{
				if (g_InArr[CompIdx].Value > g_InArr[TmpIdx].Value)
				{
					FnSwap(&TmpIdx, TmpIdx, CompIdx);
				}
				else if (g_InArr[CompIdx].Value == g_InArr[TmpIdx].Value)
				{
					if (g_InArr[CompIdx].Data > g_InArr[TmpIdx].Data)
					{
						FnSwap(&TmpIdx, TmpIdx, CompIdx);
					}
				}
			}
		}

		FnPrint();
	}

	// 종료 전 동적할당 해제
	delete[] g_InArr;

	return 0;
}
