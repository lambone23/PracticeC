/*

ex)

[입력]
4
9 1 3 0

[출력]
103
-------------------------
[입력]
5
0 0 0 0 5

[출력]
500

=========================

입력 예제
4

9 1 3 0
출력 결과
103

*/


#include <iostream>
using namespace std;

int main()
{
	// 입력
	int* InArr = nullptr;

	int n = 0;

	bool FlagValid = 0;
	int Result = 0;

	while (true)
	{
		cin >> n;

		if ((1 <= n) && (5 >= n))
		{
			break;
		}
		else
		{
			cout << "( 1 <= n <= 5 )" << endl;
		}
	}

	InArr = new int[n] {};

	for (int Idx = 0; Idx < n; Idx++)
	{
		cin >> InArr[Idx];

		if (InArr[Idx] != 0)
		{
			FlagValid = 1;
		}
	}

	// 처리
	if ((n == 1) || (n == 2))
	{
		Result = -999;
	}
	else
	{
		// 정렬 - 오름차순
		for (int Idx = 0; Idx < n - 1; Idx++)
		{
			for (int NextIdx = Idx + 1; NextIdx < n; NextIdx++)
			{
				if (InArr[Idx] > InArr[NextIdx])
				{
					int TmpNumb = InArr[Idx];
					InArr[Idx] = InArr[NextIdx];
					InArr[NextIdx] = TmpNumb;
				}
			}
		}

		if (InArr[0] != 0)
		{// 조합 중, 0이 없는 경우

			Result = InArr[0] * 100 + InArr[1] * 10 + InArr[2];
		}
		else
		{// 조합 중, 0이 있는 경우

			int FirstIdx = 0;
			int CntZero = 1;

			for (int Idx = 1; Idx < n; Idx++)
			{
				if (0 == InArr[Idx])
				{
					++CntZero;
				}

				if (0 != InArr[Idx])
				{// 0이 아닌 숫자 중, 가장 낮은 숫자의 Idx 구하기

					FirstIdx = Idx;
					break;
				}
			}

			if (CntZero >= 2)
			{// 조합 중, 0이 2개 이상

				Result = InArr[FirstIdx] * 100;
			}
			else
			{// 조합 중, 0이 1개뿐

				Result = InArr[FirstIdx] * 100 + InArr[FirstIdx + 1];
			}
		}
	}

	// 출력
	if ((Result == -999) || (FlagValid == 0))
	{
		cout << "세 자리수를 만들 수 없는 조합";
	}
	else
	{
		cout << Result;
	}

	// 종료 전 동적할당 메모리 해제
	delete[] InArr;

	return 0;
}