#include <iostream>
using namespace std;

void FnChkValid_NumberArr(int* PNumber, char* PTmpNumberARR, int* PCntNumberARR, bool* PFlagNumber)
{// 예외처리 - Number 배열

	for (int Idx = 0; Idx < 6; Idx++)
	{
		if (isalpha(PTmpNumberARR[Idx]) == 0)
		{// Number 배열에 숫자 외 입력 방지

			PNumber[Idx] = PTmpNumberARR[Idx] - '0';
			++(PCntNumberARR[PNumber[Idx]]);

			if (PCntNumberARR[PNumber[Idx]] == 1)
			{// Number 배열에 같은 숫자 입력 방지

				*PFlagNumber = 1;
			}
			else
			{
				cout << "Number에 같은 숫자는 입력되지 않습니다." << endl;
				*PFlagNumber = 0;
				break;
			}
		}
		else
		{
			*PFlagNumber = 0;
			break;
		}
	}

}//END -bool FnChkValid_NumberArr

void FnInput(int* PNumber, char* PCommand)
{
	bool FlagNumber = 0;
	bool FlagCommand = 0;

	char TmpNumberARR[6] = {};	// Number 배열에 숫자 외 입력 방지
	int CntNumberARR[10] = {};	// Number 배열에 같은 숫자 입력 방지

	bool ChkValid_NumberARR = 0;

	while (true)
	{
		// 초기화
		FlagNumber = 0;
		FlagCommand = 0;

		ChkValid_NumberARR = 0;

		for (int Idx = 0; Idx < 10; Idx++)
		{
			CntNumberARR[Idx] = 0;
		}

		// 입력 - Number 배열에 받을 숫자
		for (int Idx = 0; Idx < 6; Idx++)
		{
			cin >> TmpNumberARR[Idx];
		}

		// 예외처리 - Number 배열
		FnChkValid_NumberArr(PNumber, TmpNumberARR, CntNumberARR, &FlagNumber);

		if (FlagNumber)
		{
			// 입력 - Command 배열에 받을 문장
			for (int Idx = 0; Idx < 6; Idx++)
			{
				cin >> PCommand[Idx];
			}
			PCommand[6] = '\0';

			// 예외처리 - Command 배열
			for (int Idx = 0; Idx < 6; Idx++)
			{
				if ('m' == PCommand[Idx] || 'x' == PCommand[Idx])
				{
					FlagCommand = 1;
				}
				else
				{
					FlagCommand = 0;
					break;
				}
			}
		}

		if (FlagNumber && FlagCommand)
		{
			break;
		}
		else if ((FlagNumber) && (!FlagCommand))
		{
			cout << "m과 x로 된 한 문장을 입력" << endl;
			cout << "Number부터 다시 입력" << endl << endl;
		}
		else
		{
			cout << "Number에 6개의 숫자 입력" << endl << endl;
		}

	}//END - while (true)
}//END - void FnInput

void FnPrint(int* PArray)
{
	for (int Idx = 0; Idx < 6; Idx++)
	{
		cout << PArray[Idx];
	}
	cout << endl;
}

void FnFindMinAndMax(int* PNumber, char* PCommand, int* PFinalResult)
{
	int ChkPrevPickIdx[6] = {};	// 한번 출력한 숫자는 재출력 방지

	int Min = 999;
	int Max = PNumber[0];

	int MinIdx = 0;
	int MaxIdx = 0;

	for (int Idx = 0; Idx < 6; Idx++)
	{
		Min = 999;
		Max = PNumber[0];

		MinIdx = 0;
		MaxIdx = 0;

		if ('m' == PCommand[Idx])
		{// min값 찾기

			for (int IdxNumberARR = 0; IdxNumberARR < 6; IdxNumberARR++)
			{
				if ((Min > PNumber[IdxNumberARR]) && (ChkPrevPickIdx[IdxNumberARR] == 0))
				{
					Min = PNumber[IdxNumberARR];
					MinIdx = IdxNumberARR;
				}
			}

			PFinalResult[Idx] = Min;
			++(ChkPrevPickIdx[MinIdx]);
		}
		else
		{// Max값 찾기

			for (int IdxNumberARR = 0; IdxNumberARR < 6; IdxNumberARR++)
			{
				if ((Max < PNumber[IdxNumberARR]) && (ChkPrevPickIdx[IdxNumberARR] == 0))
				{
					Max = PNumber[IdxNumberARR];
					MaxIdx = IdxNumberARR;
				}
			}

			PFinalResult[Idx] = Max;
			++(ChkPrevPickIdx[MaxIdx]);
		}

		//FnPrint(ChkPrevPickIdx);
		//FnPrint(PFinalResult);
	}
}

int main()
{
	int Number[6] = {};
	char Command[7] = {};

	int FinalResult[6] = {};	// 최종 출력

	FnInput(Number, Command);

	FnFindMinAndMax(Number, Command, FinalResult);

	FnPrint(FinalResult);

	return 0;
}
