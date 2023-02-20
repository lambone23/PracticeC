/*

�Է� ����
6
35
69
73
83
95
99

��� ���
��99
��95
��83

*/


#include <iostream>
#include <vector>
using namespace std;

void FnPrint(vector<int>& PVect)
{
	for (int i = 0; i < PVect.size(); i++)
	{
		cout << PVect[i] << " ";
	}
	cout << endl;
}

void FnInput1(int* N)
{
	while (true)
	{
		cin >> *N;

		if ((0 <= *N) && (1000 >= *N))
		{
			break;
		}
		else
		{
			cout << "(�ִ� 1,000��)" << endl;
		}
	}
}

void FnInput2(int* PN, vector<int>& PVect)
{
	int In = 0;

	for (int i = 0; i < *PN; i++)
	{
		cin >> In;
		//Vect.insert(Vect.begin() + i, In);
		PVect.push_back(In);
	}
}

int main()
{
	// �Է�
	int N = 0;

	FnInput1(&N);

	vector<int> Vect;

	FnInput2(&N, Vect);

	//cout << endl << "Vect.size() : " << Vect.size() << endl;
	//FnPrint(Vect);

	// ó��
	int Cnt = 0;			// �� ĭ�� �迭���� ����ؼ� ���������� �ϱ� ����
	int CompIdx = 0;		// �������� �񱳴�� Idx
	int SaveCompIdx = 0;	// �������� �񱳴�� Idx�� ����ó���� ���� �Ѱܹޱ� ����
	bool FlagSwap = 0;		// �������� Swap �߻� ���� Ȯ�ο�

	for (int i = 1; i < Vect.size(); i++)
	{
		int TmpIdx = i;		// �������� ���� Idx
		CompIdx = i - 1;

		Cnt = 3;
		FlagSwap = 0;

		while (CompIdx >= 0)
		{
			SaveCompIdx = CompIdx;

			if (Vect[SaveCompIdx] < Vect[TmpIdx])
			{
				int TmpNumb = Vect[SaveCompIdx];
				Vect[SaveCompIdx] = Vect[TmpIdx];
				Vect[TmpIdx] = TmpNumb;

				TmpIdx = SaveCompIdx;
				FlagSwap = 1;
			}

			--CompIdx;
			--Cnt;

			if ((Cnt == 0) && (FlagSwap != 1))
			{	// 4ĭ �� �̻��� �� ó���� ���̻� �ʿ����� ���� ���, 
				// �������� ���� �� �̹� ���ذ��� �ּ��� ���
				break;
			}

			if ((Cnt == 0) && (FlagSwap != 0))
			{	// 4ĭ �� �̻��� �� ó���� �� �ʿ��� ���, 
				// �ٽ� 4ĭ ������ ���ϱ� ����
				SaveCompIdx = CompIdx;
				Cnt = 3;
			}
		}
	}

	// ���
	//FnPrint(Vect);
	cout << "��" << Vect[0] << endl;
	cout << "��" << Vect[1] << endl;
	cout << "��" << Vect[2] << endl;

	// ���� �� �۾�
	Vect.clear();

	return 0;
}