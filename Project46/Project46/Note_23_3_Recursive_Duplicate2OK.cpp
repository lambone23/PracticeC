#include <iostream>
using namespace std;

char* g_Path;
char g_Choco[3] = { 'A','B','C' };

// #2. visited ���
int* g_Visited;

// #1. �ؽ����̺� ���
//void FnRecursive(int Level, int* PLimitLevel, int* PLimitRepeatCnt, int* PCnt, char* PChkArray)

// #2. visited ���
void FnRecursive(int Level, int* PLimitLevel, int* PLimitRepeatCnt, int* PCnt)
{
	if (Level == *PLimitLevel)
	{
		++(*PCnt);
		return;
	}

	for (int RepeatCnt = 0; RepeatCnt < (*PLimitRepeatCnt); RepeatCnt++)
	{
		// #1. �ؽ����̺� ���
		//if (PChkArray[g_Choco[RepeatCnt]] == 2)
		//{
		//}

		// #2. visited ���
		if (2 <= g_Visited[RepeatCnt])
		{
		}
		else
		{
			g_Path[Level] = g_Choco[RepeatCnt];

			// #1. �ؽ����̺� ���
			//(PChkArray[g_Path[Level]])++;
			//FnRecursive(Level + 1, PLimitLevel, PLimitRepeatCnt, PCnt, PChkArray);
			//(PChkArray[g_Path[Level]])--;

			// #2. visited ���
			(g_Visited[RepeatCnt])++;
			FnRecursive(Level + 1, PLimitLevel, PLimitRepeatCnt, PCnt);
			(g_Visited[RepeatCnt])--;

			g_Path[Level] = 0;
		}
	}
}

int main()
{
	int n = 0;

	cin >> n;

	int Cnt = 0;

	int LimitLevel = n;		// n : ���ڷ� ����
	int LimitRepeatCnt = 3;	// 3 : ���ڷ� ����

	g_Path = new char[LimitLevel];

	// #1. �ؽ����̺� ���
	//char ChkArray[100] = {};
	//FnRecursive(0, &LimitLevel, &LimitRepeatCnt, &Cnt, ChkArray);

	// #2. visited ���
	g_Visited = new int[LimitLevel];

	for (int Idx = 0; Idx < LimitLevel; Idx++)
	{
		g_Visited[Idx] = 0;
	}

	FnRecursive(0, &LimitLevel, &LimitRepeatCnt, &Cnt);

	delete[] g_Path;

	// #2. visited ���
	delete[] g_Visited;

	cout << Cnt;

	return 0;
}
