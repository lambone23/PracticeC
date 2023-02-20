#include <iostream>
using namespace std;

// 배열 크기를 가변처리화 하기 위해 동적할당을 사용할 예정
char* g_Path;
int* g_Visited;

// 배열 크기를 고정화하여 생성시.
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
		if (g_Visited[RepeatCnt] == 0)			// 경로 중복 방지
		{
			g_Visited[RepeatCnt] = 1;			// 중복 방지용 처리
			g_Path[Level] = PName[RepeatCnt];	// 경로값 저장용

			FnRecursive(Level + 1, PName, PLimitLevel, PLimitRepeatCnt);

			// 초기화
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

	int LimitLevel = 3;		// 등수 (1 ~ 3)
	int LimitRepeatCnt = 4;	// 인원수 (4명)

	g_Path = new char[LimitLevel];		// 3 (등수)		: 경로값 저장용
	g_Visited = new int[LimitRepeatCnt];// 4 (인원수)	: 경로 중복 방지용

	for (size_t i = 0; i < LimitRepeatCnt; i++)
	{// int배열 크기를 동적할당으로 생성하였으므로 모든 요소의 값을 직접 초기화함.

		g_Visited[i] = 0;
	}

	//g_Visited[0] = 0; // 이렇게 초기화하면 오류발생하므로, 위처럼 직접 모든 요소를 초기화 하도록 함.

	FnRecursive(0, Name, &LimitLevel, &LimitRepeatCnt);

	delete[] g_Path;
	delete[] g_Visited;

	return 0;
}
