#include <iostream>
using namespace std;

int main()
{
	int A[3][3]
		= {
				2, 6, 3,
				7, 1, 1,
				3, 4, 2
	};

	int B[2][4]
		= {
				6, 4, 2, 4,
				1, 1, 5, 8
	};

	int C[2][3]
		= {
				9, 2, 3,
				4, 2, 1
	};

	int Result[3][3] = {};

	int Result_A[3] = {};
	int Result_B[3] = {};
	int Result_C[3] = {};

	int TotalPickCnt = 3;

	//============================================
	// [# 0] : 사전 작업 (2D -> 1D)
	//============================================
	int TmpA[3 * 3] = {};
	int TmpB[2 * 4] = {};
	int TmpC[2 * 3] = {};

	int TmpIdx = 0;

	// A
	for (int IdxY = 0; IdxY < 3; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			TmpA[TmpIdx++] = A[IdxY][IdxX];
		}
	}

	TmpIdx = 0;

	// B
	for (int IdxY = 0; IdxY < 2; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			TmpB[TmpIdx++] = B[IdxY][IdxX];
		}
	}

	TmpIdx = 0;

	// C
	for (int IdxY = 0; IdxY < 2; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			TmpC[TmpIdx++] = C[IdxY][IdxX];
		}
	}

	//============================================
	// [# 1-A] : A 작업 (MAX 3명 선출)
	//============================================

	for (int RepeatCnt = 0; RepeatCnt < TotalPickCnt; RepeatCnt++)
	{
		int A_Max = -999;
		int A_MaxIdx = 0;

		for (int Idx = 0; Idx < 9; Idx++)
		{
			if (A_Max < TmpA[Idx])
			{
				A_Max = TmpA[Idx];
				A_MaxIdx = Idx;
			}
		}

		for (int Idx = 0; Idx < 3; Idx++)
		{
			if (Result_A[Idx] == '\0')
			{
				Result_A[Idx] = A_Max;
				break;
			}
		}

		TmpA[A_MaxIdx] = -999;
	}

	//for (int Idx = 0; Idx < 3; Idx++)
	//{
	//	cout << Result_A[Idx] << " ";
	//}
	//cout << endl;


	//============================================
	// [# 1-B] : B 작업 (MIN 3명 선출)
	//============================================

	for (int RepeatCnt = 0; RepeatCnt < TotalPickCnt; RepeatCnt++)
	{
		int B_Min = 999;
		int B_MinIdx = 0;

		for (int Idx = 0; Idx < 8; Idx++)
		{
			if (B_Min >= TmpB[Idx])
			{
				B_Min = TmpB[Idx];
				B_MinIdx = Idx;
			}
		}

		for (int Idx = 0; Idx < 3; Idx++)
		{
			if (Result_B[Idx] == '\0')
			{
				Result_B[Idx] = B_Min;
				break;
			}
		}

		TmpB[B_MinIdx] = 999;
	}

	//for (int Idx = 0; Idx < 3; Idx++)
	//{
	//	cout << Result_B[Idx] << " ";
	//}
	//cout << endl;

	//============================================
	// [# 1-C] : C 작업 (MIN 2명, MAX 1명 선출)
	//============================================

	// 사전 작업
	int TmpC_2[6] = {};

	for (int Idx = 0; Idx < 6; Idx++)
	{
		TmpC_2[Idx] = TmpC[Idx];
	}

	// MIN 2명 선출
	for (int RepeatCnt = 0; RepeatCnt < (TotalPickCnt - 1); RepeatCnt++)
	{
		int C_Min = 999;
		int C_MinIdx = 0;

		for (int Idx = 0; Idx < 6; Idx++)
		{
			if (C_Min >= TmpC[Idx])
			{
				C_Min = TmpC[Idx];
				C_MinIdx = Idx;
			}
		}

		for (int Idx = 0; Idx < 3; Idx++)
		{
			if (Result_C[Idx] == '\0')
			{
				Result_C[Idx] = C_Min;
				break;
			}
		}

		TmpC[C_MinIdx] = 999;
	}

	for (int RepeatCnt = 0; RepeatCnt < (TotalPickCnt - 2); RepeatCnt++)
	{
		int C_Max = -999;
		int C_MaxIdx = 0;

		for (int Idx = 0; Idx < 6; Idx++)
		{
			if (C_Max < TmpC_2[Idx])
			{
				C_Max = TmpC_2[Idx];
				C_MaxIdx = Idx;
			}
		}

		for (int Idx = 0; Idx < 3; Idx++)
		{
			if (Result_C[Idx] == '\0')
			{
				Result_C[Idx] = C_Max;
				break;
			}
		}

		TmpC_2[C_MaxIdx] = -999;
	}

	//for (int Idx = 0; Idx < 3; Idx++)
	//{
	//	cout << Result_C[Idx] << " ";
	//}
	//cout << endl;

	//============================================
	// [# 2] : Result 취합
	//============================================

	for (int Idx = 0; Idx < 3; Idx++)
	{
		Result[0][Idx] = Result_A[Idx];
		Result[1][Idx] = Result_B[Idx];
		Result[2][Idx] = Result_C[Idx];
	}

	//============================================
	// [# 3] : Result 출력
	//============================================

	for (int IdxY = 0; IdxY < 3; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cout << Result[IdxY][IdxX] << " ";
		}

		cout << endl;
	}

	return 0;
}
