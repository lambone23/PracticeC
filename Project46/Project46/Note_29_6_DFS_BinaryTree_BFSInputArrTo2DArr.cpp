/*

입력 예제
ABCDE

출력 결과
ABDEC

*/


#include <iostream>
using namespace std;

#define RootIdx 0
#define Parent g_IdxSet->IdxParent
#define Child1 g_IdxSet->IdxChild1
#define Child2 g_IdxSet->IdxChild2

struct IdxFamily
{
	int IdxParent = 0;
	int IdxChild1 = 0;
	int IdxChild2 = 0;
};

IdxFamily* g_IdxSet = nullptr;

void FnPrintArray(int PArray[5][5])
{
	cout << endl;
	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		for (int IdxX = 0; IdxX < 5; IdxX++)
		{
			cout << PArray[IdxY][IdxX] << " ";
		}

		cout << endl;
	}
	cout << endl;
}

void FnSetIdxFamily(int InIdx)
{
	Parent = InIdx;
	Child1 = InIdx * 2 + 1;
	Child2 = InIdx * 2 + 2;
}

void FnRecursive(int Level, int ParentIdx, int PArray[5][5], char* PInArr)
{
	cout << PInArr[ParentIdx];

	int IdxChild1 = ParentIdx * 2 + 1;
	int IdxChild2 = ParentIdx * 2 + 2;

	if ((IdxChild1 < 5) && (IdxChild2 < 5))
	{
		if (PArray[ParentIdx][IdxChild1])
		{
			FnRecursive(Level + 1, IdxChild1, PArray, PInArr);
		}

		if (PArray[ParentIdx][IdxChild2])
		{
			FnRecursive(Level + 1, IdxChild2, PArray, PInArr);
		}
	}
	else
	{
		return;
	}
}

int main()
{
	char InArr[6] = {};

	cin >> InArr;

	int Array[5][5] = {};

	g_IdxSet = new IdxFamily;

	// 인접행렬 만들기
	for (int Idx = 0; Idx < 5; Idx++)
	{
		if (InArr[Idx] != 0)
		{
			FnSetIdxFamily(Idx);

			if ((Child1 < 5) && (Child2 < 5))
			{
				Array[Idx][Child1] = 1;
				Array[Idx][Child2] = 1;
			}
		}
	}

	//FnPrintArray(Array);

	// DFS
	FnRecursive(0, RootIdx, Array, InArr);

	delete g_IdxSet;

	return 0;
}

