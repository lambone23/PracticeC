#include <iostream>
using namespace std;

// �迭 ũ�⸦ ����ó��ȭ �ϱ� ���� �����Ҵ��� ����� ����
char* g_Path;
int* g_Visited;

// �迭 ũ�⸦ ����ȭ�Ͽ� ������.
//char g_Path[10] = {};
//int g_Visited[10] = {};

void FnRecursive(int Level, char* PName, int* PLimitLevel, int* PLimitRepeatCnt)
{
	//cout << "LEVEL : " << Level << endl;

	if (Level == *PLimitLevel)
	{
		for (int Idx = 0; Idx < (*PLimitLevel); Idx++)
		{
			cout << g_Path[Idx];
		}
		cout << endl;

		return;
	}

	for (int RepeatCnt = 0; RepeatCnt < *PLimitRepeatCnt; RepeatCnt++)
	{
		if (g_Visited[RepeatCnt] == 0)			// ��� �ߺ� ����
		{
			g_Visited[RepeatCnt] = 1;			// �ߺ� ������ ó��
			g_Path[Level] = PName[RepeatCnt];	// ��ΰ� �����

			FnRecursive(Level + 1, PName, PLimitLevel, PLimitRepeatCnt);

			// �ʱ�ȭ
			g_Path[Level] = 0;
			g_Visited[RepeatCnt] = 0;
		}
	}
}

int main()
{
	char Name[4] = {};

	for (int Idx = 0; Idx < 4; Idx++)
	{
		cin >> Name[Idx];
	}

	int LimitLevel = 3;		// ��� (1 ~ 3)
	int LimitRepeatCnt = 4;	// �ο��� (4��)

	g_Path = new char[LimitLevel];		// 3 (���)		: ��ΰ� �����
	g_Visited = new int[LimitRepeatCnt];// 4 (�ο���)	: ��� �ߺ� ������

	for (size_t i = 0; i < LimitRepeatCnt; i++)
	{// int�迭 ũ�⸦ �����Ҵ����� �����Ͽ����Ƿ� ��� ����� ���� ���� �ʱ�ȭ��.

		g_Visited[i] = 0;
	}

	//g_Visited[0] = 0; // �̷��� �ʱ�ȭ�ϸ� �����߻��ϹǷ�, ��ó�� ���� ��� ��Ҹ� �ʱ�ȭ �ϵ��� ��.

	FnRecursive(0, Name, &LimitLevel, &LimitRepeatCnt);

	delete[] g_Path;
	delete[] g_Visited;

	return 0;
}
