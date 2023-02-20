#include <iostream>
using namespace std;

int g_Arr[5] = {};
int g_Cnt = 0;
int g_Sum = 0;

void FnRecursive(int Level)
{
	if (Level == 5)
	{
		if ((10 <= g_Sum) && (20 >= g_Sum))
		{
			++(g_Cnt);
		}

		return;
	}

	g_Sum += g_Arr[Level];

	FnRecursive(Level + 1);

	g_Sum -= g_Arr[Level];

	FnRecursive(Level + 1);
}

int main()
{
	for (int Idx = 0; Idx < 5; Idx++)
	{
		cin >> g_Arr[Idx];
	}

	FnRecursive(0);

	cout << g_Cnt;

	return 0;
}
