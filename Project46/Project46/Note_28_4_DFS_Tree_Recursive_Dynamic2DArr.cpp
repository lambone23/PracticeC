/*

입력 예제
7
0 0 1 1 1 0 0
0 0 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

출력 결과
0 2 5 6 3 1 4

*/



#include <iostream>
using namespace std;

int** g_InArr = nullptr;

void FnPrint(int* PCnt)
{
	cout << endl;

	for (int Idx = 0; Idx < (*PCnt); Idx++)
	{
		cout << Idx << " ";
	}

	cout << "// <- [IdxX]" << endl;

	for (int IdxY = 0; IdxY < (*PCnt); IdxY++)
	{
		for (int IdxX = 0; IdxX < (*PCnt); IdxX++)
		{
			cout << g_InArr[IdxY][IdxX] << " ";
		}

		cout << "// <- [IdxY] : " << IdxY << endl;
	}

	cout << endl;
}

void FnRecursive(int Level, int* PCnt, int NodeNnumb)
{
	//cout << "Level : "<< Level << ", NodeNnumb: " << NodeNnumb << " " << endl;
	cout << NodeNnumb << " ";

	int CntDoRecursive = 0;

	int* ListDoRecursive = new int[(*PCnt) + 1] {};

	for (int IdxX = 0; IdxX < (*PCnt); IdxX++)
	{
		if (g_InArr[NodeNnumb][IdxX] == 1)
		{
			ListDoRecursive[IdxX] = IdxX;

			CntDoRecursive++;
		}
	}

	//cout << "CntDoRecursive : " << CntDoRecursive << endl;

	if (CntDoRecursive == 0)
	{
		//cout << "Retrun - Level : " << Level << ", NodeNnumb: " << NodeNnumb << " " << endl;
		delete[] ListDoRecursive;

		return;
	}

	for (int Idx = 0; Idx < (*PCnt); Idx++)
	{
		if (ListDoRecursive[Idx] > 0)
		{
			FnRecursive(Level + 1, PCnt, Idx);
		}
	}

	delete[] ListDoRecursive;
}

int main()
{
	//============================================
	// 입력
	//============================================

	int Cnt = 0;

	cin >> Cnt;

	g_InArr = new int* [(Cnt + 1)] {};

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		g_InArr[Idx] = new int[(Cnt + 1)] {};
	}

	for (int IdxY = 0; IdxY < Cnt; IdxY++)
	{
		for (int IdxX = 0; IdxX < Cnt; IdxX++)
		{
			cin >> g_InArr[IdxY][IdxX];
		}
	}

	cout << endl;
	//FnPrint(&Cnt);

	//============================================
	// DFS
	//============================================

	bool FlagDoRecursiv = 0;
	int RootIdxX = 0;

	for (int IdxX = 0; IdxX < Cnt; IdxX++)
	{
		for (int IdxY = 0; IdxY < Cnt; IdxY++)
		{
			if (g_InArr[IdxY][IdxX] == 0)
			{
				RootIdxX = IdxX;
				FlagDoRecursiv = 1;
			}
			else
			{
				FlagDoRecursiv = 0;
			}
		}

		if (FlagDoRecursiv)
		{
			break;
		}
	}

	//cout << "FlagDoRecursiv : "<< FlagDoRecursiv << endl;
	//cout << "RootIdxX : " << RootIdxX << endl;

	if (FlagDoRecursiv)
	{
		FnRecursive(0, &Cnt, RootIdxX);
	}

	//============================================
	// 후처리 - 동적할당 해제
	//============================================

	for (int Idx = 0; Idx < (Cnt + 1); Idx++)
	{
		delete[] g_InArr[Idx];
	}

	delete[] g_InArr;

	return 0;
}