/*

입력 예제
9
0 1 1 0 0 0 0 0 0
0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

출력 결과
0 1 3
0 1 4
0 1 5
0 2 6
0 2 7
0 2 8

*/


#include <iostream>
using namespace std;

int* g_Path = nullptr;
int** g_InArrTree = nullptr;

void FnRecursive(int Level, int* PCnt, int NodeNumb)
{
	if (Level == 2)
	{
		for (int Idx = 0; Idx < 3; Idx++)
		{
			cout << g_Path[Idx] << " ";
		}
		cout << endl;
	}

	bool FlagDoRecursive = 0;

	int* ListDoRecursive = new int[(*PCnt + 1)] {};

	for (int IdxX = 0; IdxX < (*PCnt); IdxX++)
	{
		if (g_InArrTree[NodeNumb][IdxX] == 1)
		{
			++(ListDoRecursive[IdxX]);
			FlagDoRecursive = 1;
		}
	}

	if (!FlagDoRecursive)
	{
		delete[] ListDoRecursive;

		return;
	}

	for (int Idx = 0; Idx < (*PCnt); Idx++)
	{
		if (ListDoRecursive[Idx] > 0)
		{
			g_Path[Level] = NodeNumb;
			g_Path[Level + 1] = Idx;

			FnRecursive(Level + 1, PCnt, Idx);

			g_Path[Level + 1] = 0;
			g_Path[Level] = 0;
		}
	}

	delete[] ListDoRecursive;
}

int main()
{
	//==================================
	// 입력
	//==================================

	int InputValue = 0;

	cin >> InputValue;

	g_Path = new int [(InputValue + 1)] {};

	g_InArrTree = new int* [(InputValue + 1)] {};

	for (int Idx = 0; Idx < InputValue; Idx++)
	{
		g_InArrTree[Idx] = new int[(InputValue + 1)] {};
	}

	for (int IdxY = 0; IdxY < InputValue; IdxY++)
	{
		for (int IdxX = 0; IdxX < InputValue; IdxX++)
		{
			cin >> g_InArrTree[IdxY][IdxX];
		}
	}

	cout << endl;

	//==================================
	// DFS
	//==================================

	bool FlagRootExistence = 0;
	int RootIdxX = 0;

	for (int IdxX = 0; IdxX < InputValue; IdxX++)
	{
		for (int IdxY = 0; IdxY < InputValue; IdxY++)
		{
			if (g_InArrTree[IdxY][IdxX] == 0)
			{
				RootIdxX = IdxX;
				FlagRootExistence = 1;
			}
			else
			{
				FlagRootExistence = 0;
				break;
			}
		}

		if (FlagRootExistence)
		{
			break;
		}
	}

	if (FlagRootExistence)
	{
		FnRecursive(0, &InputValue, RootIdxX);
	}

	//==================================
	// 후처리 - 동적할당 메모리 해제
	//==================================

	delete[] g_Path;

	for (int Idx = 0; Idx < (InputValue + 1); Idx++)
	{
		delete[] g_InArrTree[Idx];
	}

	delete[] g_InArrTree;

	return 0;
}