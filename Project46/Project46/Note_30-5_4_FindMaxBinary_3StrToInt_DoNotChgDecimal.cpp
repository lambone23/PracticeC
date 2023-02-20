/*

입력 예제
1001011
11110
1101110

출력 결과
1101110

*/


#include <iostream>
using namespace std;

struct StrInfo
{
	int InIdx;
	int Data;
};

int FnCharToInt(char* PArray)
{
	int ReturnValue = 0;

	int Length = strlen(PArray);
	int Cnt = Length;
	int Result = 0;
	int Numb = 1;

	for (int Idx = 0; Idx < Length; Idx++)
	{
		if ((Idx == (Length - 1)) && ('1' == PArray[Idx]))
		{
			Result += 1;
		}
		else if ('1' == PArray[Idx])
		{
			for (int RepeatCnt = 1; RepeatCnt < Cnt; RepeatCnt++)
			{
				Numb *= 10;
			}

			Result += Numb;
			Numb = 1;
		}

		--(Cnt);
	}

	ReturnValue = Result;

	return ReturnValue;
}

int main()
{
	// 입력
	const int CntStr = 3;

	char Str[CntStr][31] = {};

	cin >> Str[0] >> Str[1] >> Str[2];

	// 변환 : Char -> int
	StrInfo StrInt[CntStr] = {};

	for (int Idx = 0; Idx < CntStr; Idx++)
	{
		StrInt[Idx].InIdx = Idx;
		StrInt[Idx].Data = FnCharToInt(Str[Idx]);
	}

	// 변환된 int 값을 내림차순 정렬
	for (int Idx = 0; Idx < CntStr - 1; Idx++)
	{
		for (int NextIdx = Idx + 1; NextIdx < CntStr; NextIdx++)
		{
			if (StrInt[Idx].Data < StrInt[NextIdx].Data)
			{
				StrInfo Tmp = StrInt[Idx];
				StrInt[Idx] = StrInt[NextIdx];
				StrInt[NextIdx] = Tmp;
			}
		}
	}

	// 가장 큰 인풋값 출력
	cout << Str[StrInt[0].InIdx];

	return 0;
}



/*
#include <iostream>
using namespace std;

char Str[3][31] = {};

void FnPrintMax(int LimitLength, int Y1, int Y2)
{
	for (int Idx = 0; Idx < LimitLength; Idx++)
	{
		if (Str[Y1][Idx] != Str[Y2][Idx])
		{
			if (Str[Y1][Idx] == '1')
			{
				cout << Str[Y1];
			}
			else
			{
				cout << Str[Y2];
			}

			break;
		}
	}
}

int main()
{
	cin >> Str[0] >> Str[1] >> Str[2];

	int LenArr[3] = {};

	LenArr[0] = strlen(Str[0]);
	LenArr[1] = strlen(Str[1]);
	LenArr[2] = strlen(Str[2]);

	if ((LenArr[0] > LenArr[1]) && (LenArr[0] > LenArr[2]))
	{
		cout << Str[0];
	}
	else if ((LenArr[1] > LenArr[0]) && (LenArr[1] > LenArr[2]))
	{
		cout << Str[1];
	}
	else if ((LenArr[2] > LenArr[0]) && (LenArr[2] > LenArr[1]))
	{
		cout << Str[2];
	}

	else if ((LenArr[0] != LenArr[1]) && (LenArr[1] == LenArr[2]))
	{
		FnPrintMax(LenArr[1], 1, 2);
	}
	else if ((LenArr[1] != LenArr[0]) && (LenArr[0] == LenArr[2]))
	{
		FnPrintMax(LenArr[0], 0, 2);
	}
	else if ((LenArr[2] != LenArr[0]) && (LenArr[0] == LenArr[1]))
	{
		FnPrintMax(LenArr[0], 0, 1);
	}

	return 0;
}
*/