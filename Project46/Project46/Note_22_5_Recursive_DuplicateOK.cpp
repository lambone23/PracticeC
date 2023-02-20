#include <iostream>
using namespace std;

int g_Path[10] = {};

void FnRecursive(int Level, int* PDay, int* PHeadCnt)
{
	if (Level == *PDay)
	{
		for (int RepeatCnt = 0; RepeatCnt < *PDay; RepeatCnt++)
		{
			cout << g_Path[RepeatCnt] << " ";
		}

		cout << endl;
		return;
	}

	for (int RepeatCnt = 0; RepeatCnt < *PHeadCnt; RepeatCnt++)
	{
		g_Path[Level] = (RepeatCnt + 1);
		FnRecursive((Level + 1), PDay, PHeadCnt);
		g_Path[Level] = 0;
	}
}

int main()
{
	int Day = 4;

	int HeadCnt = 0;

	cin >> HeadCnt;

	FnRecursive(0, &Day, &HeadCnt);

	return 0;
}
