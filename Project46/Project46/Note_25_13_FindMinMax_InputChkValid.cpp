#include <iostream>
using namespace std;

void FnChkValid_NumberArr(int* PNumber, char* PTmpNumberARR, int* PCntNumberARR, bool* PFlagNumber)
{// ����ó�� - Number �迭

	for (int Idx = 0; Idx < 6; Idx++)
	{
		if (isalpha(PTmpNumberARR[Idx]) == 0)
		{// Number �迭�� ���� �� �Է� ����

			PNumber[Idx] = PTmpNumberARR[Idx] - '0';
			++(PCntNumberARR[PNumber[Idx]]);

			if (PCntNumberARR[PNumber[Idx]] == 1)
			{// Number �迭�� ���� ���� �Է� ����

				*PFlagNumber = 1;
			}
			else
			{
				cout << "Number�� ���� ���ڴ� �Էµ��� �ʽ��ϴ�." << endl;
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

	char TmpNumberARR[6] = {};	// Number �迭�� ���� �� �Է� ����
	int CntNumberARR[10] = {};	// Number �迭�� ���� ���� �Է� ����

	bool ChkValid_NumberARR = 0;

	while (true)
	{
		// �ʱ�ȭ
		FlagNumber = 0;
		FlagCommand = 0;

		ChkValid_NumberARR = 0;

		for (int Idx = 0; Idx < 10; Idx++)
		{
			CntNumberARR[Idx] = 0;
		}

		// �Է� - Number �迭�� ���� ����
		for (int Idx = 0; Idx < 6; Idx++)
		{
			cin >> TmpNumberARR[Idx];
		}

		// ����ó�� - Number �迭
		FnChkValid_NumberArr(PNumber, TmpNumberARR, CntNumberARR, &FlagNumber);

		if (FlagNumber)
		{
			// �Է� - Command �迭�� ���� ����
			for (int Idx = 0; Idx < 6; Idx++)
			{
				cin >> PCommand[Idx];
			}
			PCommand[6] = '\0';

			// ����ó�� - Command �迭
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
			cout << "m�� x�� �� �� ������ �Է�" << endl;
			cout << "Number���� �ٽ� �Է�" << endl << endl;
		}
		else
		{
			cout << "Number�� 6���� ���� �Է�" << endl << endl;
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
	int ChkPrevPickIdx[6] = {};	// �ѹ� ����� ���ڴ� ����� ����

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
		{// min�� ã��

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
		{// Max�� ã��

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

	int FinalResult[6] = {};	// ���� ���

	FnInput(Number, Command);

	FnFindMinAndMax(Number, Command, FinalResult);

	FnPrint(FinalResult);

	return 0;
}
