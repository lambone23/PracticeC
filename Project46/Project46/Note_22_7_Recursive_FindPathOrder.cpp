#include <iostream>
using namespace std;

char g_Path[10] = {};
int g_PathCnt[1] = { 0 };

char g_Input[3] = {};

void FnRecursive(int Level)
{
	if (Level == 3)
	{
		++g_PathCnt[0];

		if (
			(g_Path[0] == g_Input[0]) &&
			(g_Path[1] == g_Input[1]) &&
			(g_Path[2] == g_Input[2])
			)
		{
			cout << g_PathCnt[0] << "¹øÂ°";
		}

		return;
	}

	for (int RepeatCnt = 0; RepeatCnt < 4; RepeatCnt++)
	{
		g_Path[Level] = RepeatCnt + 'A';

		FnRecursive(Level + 1);

		g_Path[Level] = 0;
	}

}

int main()
{
	cin >> g_Input[0] >> g_Input[1] >> g_Input[2];

	FnRecursive(0);
}
