#include <iostream>
using namespace std;

char g_OX[2] = { 'O','X' };
char* g_Path;

void FnRecursive(int Level, int* PHeadCnt)
{
	if (Level == *PHeadCnt)
	{
		for (int Idx = 0; Idx < *PHeadCnt; Idx++)
		{
			cout << g_Path[Idx];
		}
		cout << endl;

		return;
	}

	for (int RepeatCnt = 0; RepeatCnt < 2; RepeatCnt++)
	{
		g_Path[Level] = g_OX[RepeatCnt];

		FnRecursive(Level + 1, PHeadCnt);

		g_Path[Level] = 0;
	}
}

int main()
{
	int HeadCnt = 0;

	cin >> HeadCnt;

	g_Path = new char[HeadCnt];

	if (HeadCnt <= 0)
	{
		cout << "데이트 조합을 만들 수 없음";
	}
	else
	{
		FnRecursive(0, &HeadCnt);

		delete[] g_Path;
	}

	return 0;
}
