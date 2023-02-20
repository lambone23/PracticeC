/*

입력 예제
ABABCGKABABC
BTBCKABABCT

출력 결과
KABABC

*/



#include <iostream>
using namespace std;

struct StartInfo
{
	int Y;
	int X;
	int Len1;
	int Len2;
};

struct NowInfo
{
	int Y;
	int X;
};

struct MaxInfo
{
	int Len;
	int Y;
	int X;
};

int** g_Array2D = nullptr;

StartInfo g_Start = {};
NowInfo g_Now = {};
MaxInfo g_Max = {};

void FnRecursive(int Level)
{
	if (Level == 1)
	{
		g_Now.Y = g_Start.Y;
		g_Now.X = g_Start.X;
	}

	// 두 문장의 각각의 다음 인덱스를 구함
	int DirectY = g_Now.Y + 1;
	int DirectX = g_Now.X + 1;

	if ((g_Start.Len1 > DirectY) && (g_Start.Len2 > DirectX))
	{
		if (g_Array2D[DirectY][DirectX] == 1)
		{// 두 문장 각각의 다음 철자도 같은 경우

			g_Now.Y = DirectY;
			g_Now.X = DirectX;

			if ((g_Max.Len) < (Level + 1))
			{
				g_Max.Len = Level + 1;
				g_Max.Y = g_Start.Y;
				g_Max.X = g_Start.X;
			}

			// 그 다음 철자도 같을지 확인하기 위하여, 재귀 탐색 실행.
			FnRecursive(Level + 1);
		}
		else
		{// 두 문장 각각의 다음 철자가 같지 않은 경우. 재귀 탐색 종료.

			return;
		}
	}
	else
	{
		// 두 문장 각각의 다음 인덱스 중, 
		// 하나라도 각 문장의 길이를 벗어난 경우, 재귀 탐색 종료.

		return;
	}
}

int main()
{
	//==========================================
	// # 1. 입력
	//==========================================
	char Str1[16] = {};
	char Str2[16] = {};

	cin >> Str1 >> Str2;

	//==========================================
	// # 2. 입력값을 인접행렬화
	//==========================================
	int Len1 = strlen(Str1);
	int Len2 = strlen(Str2);

	// 동적할당으로 2D배열 생성
	g_Array2D = new int* [Len1 + 1];

	for (int Idx = 0; Idx < Len1 + 1; Idx++)
	{
		g_Array2D[Idx] = new int[Len2 + 1];
	}

	// 입력값으로 인접행렬 만들기
	for (int IdxY = 0; IdxY < Len1; IdxY++)
	{
		for (int IdxX = 0; IdxX < Len2; IdxX++)
		{
			if (Str1[IdxY] == Str2[IdxX])
			{
				g_Array2D[IdxY][IdxX] = 1;
			}
			else
			{
				g_Array2D[IdxY][IdxX] = 0;
			}
		}
	}

	//cout << endl;
	//for (int IdxY = 0; IdxY < Len1; IdxY++)
	//{
	//	for (int IdxX = 0; IdxX < Len2; IdxX++)
	//	{
	//		cout << g_Array2D[IdxY][IdxX] << " ";
	//	}

	//	cout << endl;
	//}
	//cout << endl;

	//==========================================
	// # 3. 처리
	//==========================================

	g_Max.Len = 0;

	for (int IdxY = 0; IdxY < Len1; IdxY++)
	{// g_Array2D -Y
		for (int IdxX = 0; IdxX < Len2; IdxX++)
		{// g_Array2D -X

			if (g_Array2D[IdxY][IdxX] == 1)
			{
				g_Start.Y = IdxY;
				g_Start.X = IdxX;
				g_Start.Len1 = Len1;
				g_Start.Len2 = Len2;

				FnRecursive(1);
			}
		}
	}

	if ((g_Max.Len) != 0)
	{
		// 출력 방법 1
		int Y = g_Max.Y;

		for (int RepeatCnt = 0; RepeatCnt < (g_Max.Len); RepeatCnt++)
		{
			cout << Str1[Y++];
		}

		// 출력 방법 2
		//int X = g_Max.X;

		//for (int RepeatCnt = 0; RepeatCnt < (g_Max.Len); RepeatCnt++)
		//{
		//	cout << Str2[X++];
		//}
	}
	else
	{
		cout << "입력받은 두 문장은 일치하는 부분이 전혀 없음" << endl;
	}

	//==========================================
	// # 4. 종료 전 동적할당 해제
	//==========================================

	for (int Idx = 0; Idx < Len1; Idx++)
	{
		delete[] g_Array2D[Idx];
	}

	delete[] g_Array2D;

	return 0;
}
