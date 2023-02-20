#include <iostream>
using namespace std;

char g_Path[3] = {};
char g_OX[2] = { 'O','X' };

void FnResultPrint()
{
	int Win = 0;
	int Lose = 0;

	for (int i = 0; i < 3; i++)
	{
		if (g_Path[i] == 'O')
		{
			++Win;
		}
		else
		{
			++Lose;
		}
	}

	if (Win > 0)
	{
		cout << Win << "½Â";
	}

	if (Lose > 0)
	{
		cout << Lose << "ÆÐ";
	}

	cout << "("
		<< (g_Path[0] == 'O' ? "½Â" : "ÆÐ")
		<< (g_Path[1] == 'O' ? "½Â" : "ÆÐ")
		<< (g_Path[2] == 'O' ? "½Â" : "ÆÐ")
		<< ")" << endl;

}//END - void FnResultPrint

void FnRecursive(int Level, int* PLimitLevel, int* PRepeatCnt)
{
	if (Level == *PLimitLevel)
	{
		FnResultPrint();

		return;
	}

	for (int RepeatCnt = 0; RepeatCnt < (*PRepeatCnt); RepeatCnt++)
	{
		g_Path[Level] = g_OX[RepeatCnt];

		FnRecursive(Level + 1, PLimitLevel, PRepeatCnt);

		g_Path[Level] = ' ';
	}
}

int main()
{
	int LimitLevel = 3;
	int RepeatCnt = 2;

	FnRecursive(0, &LimitLevel, &RepeatCnt);

	return 0;
}
