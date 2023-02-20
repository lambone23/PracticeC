/*

입력 예제
1 1 1
2 2 2
3 3 3

1 2 3
1 2 3
1 2 3

출력 결과
1

*/



#include <iostream>
using namespace std;

int main()
{
	int a[3][3] = {};
	int b[3][3] = {};

	int Tmp_a[9] = {};
	int IdxTmp_a = 0;

	for (int IdxY = 0; IdxY < 3; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cin >> a[IdxY][IdxX];

			Tmp_a[IdxTmp_a++] = a[IdxY][IdxX];
		}
	}

	for (int IdxY = 0; IdxY < 3; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cin >> b[IdxY][IdxX];
		}
	}

	int Direct[4][4]
		= {
			{0,0,2,0},
			{2,0,2,2},
			{2,2,0,2},
			{0,2,0,0}
	};

	int CmpNumb_a1 = a[0][0];
	int CmpNumb_a2 = a[2][0];

	int CmpNumb_b1 = 0;
	int CmpNumb_b2 = 0;

	int CntTurn = -999;
	bool FlagSame = 0;

	for (int i = 0; i < 4; i++)
	{
		int Y1 = Direct[i][0];
		int X1 = Direct[i][1];

		int Y2 = Direct[i][2];
		int X2 = Direct[i][3];

		CmpNumb_b1 = b[Y1][X1];
		CmpNumb_b2 = b[Y2][X2];

		if (
			(CmpNumb_a1 == CmpNumb_b1) &&
			(CmpNumb_a2 == CmpNumb_b2)
			)
		{
			CntTurn = i;
			break;
		}
	}

	if (CntTurn != -999)
	{
		IdxTmp_a = 0;

		if (0 == CntTurn)
		{
			//cout << endl << "===== 0" << endl;

			for (int IdxY = 0; IdxY < 3; IdxY++)
			{
				for (int IdxX = 0; IdxX < 3; IdxX++)
				{
					//cout << a[IdxY][IdxX] << ",";
					//cout << b[IdxY][IdxX] << endl;

					if (a[IdxY][IdxX] == b[IdxY][IdxX])
					{
						FlagSame = 1;
					}
					else
					{
						FlagSame = 0;
						break;
					}
				}

				if (!FlagSame)
				{
					break;
				}
			}
		}
		else if (1 == CntTurn)
		{
			//cout << endl << "===== 1" << endl;

			for (int IdxX = 0; IdxX < 3; IdxX++)
			{
				for (int IdxY = 2; IdxY >= 0; IdxY--)
				{
					//cout << Tmp_a[IdxTmp_a] << ",";
					//cout << b[IdxY][IdxX] << endl;

					if (Tmp_a[IdxTmp_a++] == b[IdxY][IdxX])
					{
						FlagSame = 1;
					}
					else
					{
						FlagSame = 0;
						break;
					}
				}

				if (!FlagSame)
				{
					break;
				}
			}
		}
		else if (2 == CntTurn)
		{
			//cout << endl << "===== 2" << endl;

			for (int IdxY = 2; IdxY >= 0; IdxY--)
			{
				for (int IdxX = 2; IdxX >= 0; IdxX--)
				{
					//cout << Tmp_a[IdxTmp_a] << ",";
					//cout << b[IdxY][IdxX] << endl;

					if (Tmp_a[IdxTmp_a++] == b[IdxY][IdxX])
					{
						FlagSame = 1;
					}
					else
					{
						FlagSame = 0;
						break;
					}
				}

				if (!FlagSame)
				{
					break;
				}
			}
		}
		else if (3 == CntTurn)
		{
			//cout << endl << "===== 3" << endl;

			for (int IdxX = 2; IdxX >= 0; IdxX--)
			{
				for (int IdxY = 0; IdxY < 3; IdxY++)
				{
					//cout << Tmp_a[IdxTmp_a] << ",";
					//cout << b[IdxY][IdxX] << endl;

					if (Tmp_a[IdxTmp_a++] == b[IdxY][IdxX])
					{
						FlagSame = 1;
					}
					else
					{
						FlagSame = 0;
						break;
					}
				}

				if (!FlagSame)
				{
					break;
				}
			}
		}
	}

	if (FlagSame)
	{
		cout << endl << CntTurn << endl;
	}
	else
	{
		cout << endl << "a블럭과 b블럭은 아무 관련이 없음." << endl;
	}

	return 0;
}