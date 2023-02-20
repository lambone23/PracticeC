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
			cout << "B�� F�� �� ������ �Է� (�ִ� ���ڼ��� 10����)" << endl;
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

	FnInput(InArr); // �Է°� �ޱ�

	/*
		[1]. 'B'�� ������ 'F'�� ������ ��ġ�ؾ� �Ѵ�.

		[2]. 'F'�� 'B'���� ���� ���� �ȵ�.
			- ���� ó�� ã�� 'B' �� ���� ó�� ã�� 'F'���� �� ��Ʈ
			- ���� ã�� �������� �� �� ��Ʈ.. �迭�� ���� �ε������� ��Ʈ�� �θ�?
	*/

	int IdxArr_B[20] = {}; // B�� �ε����� ��� �迭
	int IdxArr_F[20] = {}; // F�� �ε����� ��� �迭

	int Idx_B = 0; // �迭 IdxArr_B�� �ε���
	int Idx_F = 0; // �迭 IdxArr_F�� �ε���

	int Cnt_B = 0; // �Է� ���忡�� B�� ���� ī��Ʈ
	int Cnt_F = 0; // �Է� ���忡�� F�� ���� ī��Ʈ

	bool FlagSetOK = 0; // ����ó�� üũ

	//FnDebugPrint(0, InArr, IdxArr_B, &Cnt_B, IdxArr_F, &Cnt_F); // �����

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

	//FnDebugPrint(1, InArr, IdxArr_B, &Cnt_B, IdxArr_F, &Cnt_F); // �����

	// ����ó�� - [1]
	if (Cnt_B != Cnt_F)
	{
		FlagSetOK = 0; // B�� F�� ���� ���� ����ġ
	}
	else
	{
		FlagSetOK = 1;
	}

	// ����ó�� - [2]
	if (FlagSetOK)
	{// B�� F�� ���� ������ ��ġ�ϴ� ���

		for (int Idx = 0; Idx < 10; Idx++)
		{
			if (IdxArr_F[Idx] < IdxArr_B[Idx])
			{// B���� F�� ���� ������

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
		cout << "¦�̸���";
	}
	else
	{
		cout << "¦�̾ȸ���";
	}

	return 0;
}

