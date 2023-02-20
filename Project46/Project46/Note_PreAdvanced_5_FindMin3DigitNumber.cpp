/*

ex)

[�Է�]
4
9 1 3 0

[���]
103
-------------------------
[�Է�]
5
0 0 0 0 5

[���]
500

=========================

�Է� ����
4

9 1 3 0
��� ���
103

*/


#include <iostream>
using namespace std;

int main()
{
	// �Է�
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

	// ó��
	if ((n == 1) || (n == 2))
	{
		Result = -999;
	}
	else
	{
		// ���� - ��������
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
		{// ���� ��, 0�� ���� ���

			Result = InArr[0] * 100 + InArr[1] * 10 + InArr[2];
		}
		else
		{// ���� ��, 0�� �ִ� ���

			int FirstIdx = 0;
			int CntZero = 1;

			for (int Idx = 1; Idx < n; Idx++)
			{
				if (0 == InArr[Idx])
				{
					++CntZero;
				}

				if (0 != InArr[Idx])
				{// 0�� �ƴ� ���� ��, ���� ���� ������ Idx ���ϱ�

					FirstIdx = Idx;
					break;
				}
			}

			if (CntZero >= 2)
			{// ���� ��, 0�� 2�� �̻�

				Result = InArr[FirstIdx] * 100;
			}
			else
			{// ���� ��, 0�� 1����

				Result = InArr[FirstIdx] * 100 + InArr[FirstIdx + 1];
			}
		}
	}

	// ���
	if ((Result == -999) || (FlagValid == 0))
	{
		cout << "�� �ڸ����� ���� �� ���� ����";
	}
	else
	{
		cout << Result;
	}

	// ���� �� �����Ҵ� �޸� ����
	delete[] InArr;

	return 0;
}