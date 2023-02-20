#include <iostream>
using namespace std;

void FnInput(char* PArray)
{
	bool FlagValid = 0;

	while (true)
	{
		cin >> PArray;

		for (int Idx = 0; Idx < 10; Idx++)
		{
			if (PArray[Idx] != '\0')
			{
				if (('B' == PArray[Idx]) || ('F' == PArray[Idx]))
				{
					FlagValid = 1;
				}
				else
				{
					FlagValid = 0;
				}
			}
		}

		if (FlagValid)
		{
			break;
		}
		else
		{
			cout << "B와 F로 된 문장을 입력 (최대 글자수는 10글자)" << endl;
		}
	}
}//END - void FnInput

void FnDebugPrint(int Numb, char* PInArr, int* PIdxArr_B, int* PCnt_B, int* PIdxArr_F, int* PCnt_F)
{
	if (0 == Numb)
	{
		cout << "Index : ";
		for (int Idx = 0; Idx < 10; Idx++)
		{
			cout << Idx << " ";
		}
		cout << endl;

		cout << "InArr : ";
		for (int Idx = 0; Idx < 10; Idx++)
		{
			cout << PInArr[Idx] << " ";
		}
		cout << endl;
	}
	else if (1 == Numb)
	{
		cout << "IdxArr_B : ";
		for (int Idx = 0; Idx < 10; Idx++)
		{
			cout << PIdxArr_B[Idx] << " ";
		}
		cout << "| Cnt_B : " << (*PCnt_B);
		cout << endl;

		cout << "IdxArr_F : ";
		for (int Idx = 0; Idx < 10; Idx++)
		{
			cout << PIdxArr_F[Idx] << " ";
		}
		cout << "| Cnt_F : " << (*PCnt_F);
		cout << endl;
	}
}//END - void FnDebugPrint

int main()
{
	char InArr[11] = {};

	FnInput(InArr); // 입력값 받기

	/*
		[1]. 'B'의 개수와 'F'의 개수가 일치해야 한다.

		[2]. 'F'가 'B'보다 먼저 오면 안됨.
			- 가장 처음 찾은 'B' 와 가장 처음 찾는 'F'끼리 한 세트
			- 다음 찾은 순서끼리 또 한 세트.. 배열로 같은 인덱스끼리 세트로 두면?
	*/

	int IdxArr_B[20] = {}; // B의 인덱스만 담는 배열
	int IdxArr_F[20] = {}; // F의 인덱스만 담는 배열

	int Idx_B = 0; // 배열 IdxArr_B의 인덱스
	int Idx_F = 0; // 배열 IdxArr_F의 인덱스

	int Cnt_B = 0; // 입력 문장에서 B의 개수 카운트
	int Cnt_F = 0; // 입력 문장에서 F의 개수 카운트

	bool FlagSetOK = 0; // 예외처리 체크

	//FnDebugPrint(0, InArr, IdxArr_B, &Cnt_B, IdxArr_F, &Cnt_F); // 디버깅

	// 
	for (int Idx = 0; Idx < 10; Idx++)
	{
		if ('B' == InArr[Idx])
		{
			IdxArr_B[(Idx_B)++] = Idx;
			++(Cnt_B);
		}

		if ('F' == InArr[Idx])
		{
			IdxArr_F[(Idx_F)++] = Idx;
			++(Cnt_F);
		}
	}

	//FnDebugPrint(1, InArr, IdxArr_B, &Cnt_B, IdxArr_F, &Cnt_F); // 디버깅

	// 예외처리 - [1]
	if (Cnt_B != Cnt_F)
	{
		FlagSetOK = 0; // B와 F의 각각 개수 불일치
	}
	else
	{
		FlagSetOK = 1;
	}

	// 예외처리 - [2]
	if (FlagSetOK)
	{// B와 F의 각각 개수는 일치하는 경우

		for (int Idx = 0; Idx < 10; Idx++)
		{
			if (IdxArr_F[Idx] < IdxArr_B[Idx])
			{// B보다 F가 먼저 시작함

				FlagSetOK = 0;
				break;
			}
			else
			{
				FlagSetOK = 1;
			}

		}
	}

	if (FlagSetOK)
	{
		cout << "짝이맞음";
	}
	else
	{
		cout << "짝이안맞음";
	}

	return 0;
}

