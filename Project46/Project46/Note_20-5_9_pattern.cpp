#include <iostream>
using namespace std;

int FnChkSum(int PArray[4][5], int* PArrayY, int* PArrayX, int InY, int InX)
{
	int ReturnValue = 0;

	int Sum = 0;

	for (int ChkY = *PArrayY; ChkY < *PArrayY + InY; ChkY++)
	{
		for (int ChkX = *PArrayX; ChkX < *PArrayX + InX; ChkX++)
		{
			//[S] : ������������������������������������������
			//cout << "(" << *PArrayY << "," << *PArrayX << ") : "	// �迭 ������ ��ǥ
			//	<< "(" << ChkY << "," << ChkX << ") : "				// ���� ���� ��ǥ
			//	<< PArray[ChkY][ChkX] << endl;						// �ش� ��ǥ�� ��
			//[E] : ������������������������������������������

			Sum = Sum + PArray[ChkY][ChkX];

		}
	}

	ReturnValue = Sum;

	//[S] : ������������������������������������������
	//cout << "(" << *PArrayY << "," << *PArrayX << ") : Sum : "	// �迭 ������ ��ǥ
	//	<< ReturnValue << endl;									// ���� ����ȭ ��
	//[E] : ������������������������������������������

	return ReturnValue;

}//END - int FnChkPatternSum

void FnChkMaxSumPos(int PArray[4][5], int* PInY, int* PInX, int* PReturnMaxY, int* PReturnMaxX)
{

	/*

	[Y][X]		[Y][X+1]		[Y][X+2]		[Y][X+3]		[Y][X+4]
	[Y+1][X]	[Y+1][X+1]		[Y+1][X+2]		[Y+1][X+3]		[Y+1][X+4]
	[Y+2][X]	[Y+2][X+1]		[Y+2][X+2]		[Y+2][X+3]		[Y+2][X+4]
	[Y+3][X]	[Y+3][X+1]		[Y+3][X+2]		[Y+3][X+3]		[Y+3][X+4]

	*/

	int MaxSum = 0;

	int MaxY = 0;
	int MaxX = 0;

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{// PArray - Y
		for (int IdxX = 0; IdxX < 5; IdxX++)
		{// PArray - X

			if (// ��ǥ�κ����� ���� ũ�⸦ �������� �� ������ �迭�� �Ѿ�� �ʵ��� ����ó��
				((IdxY + *PInY) <= 4) &&
				((IdxX + *PInX) <= 5)
				)
			{

				int Result_FnChkSum = FnChkSum(PArray, &IdxY, &IdxX, *PInY, *PInX);


				//[S] : ������������������������������������������
				//cout << endl;
				//[E] : ������������������������������������������

				if (MaxSum < Result_FnChkSum)
				{
					MaxSum = Result_FnChkSum;
					MaxY = IdxY;
					MaxX = IdxX;
				}
			}

		}
	}

	*PReturnMaxY = MaxY;
	*PReturnMaxX = MaxX;

}//END - void FnChkMaxSumPos

void FnPrint(int* PMaxSumY, int* PMaxSumX)
{
	cout << "(" << *PMaxSumY << "," << *PMaxSumX << ")";

}//END - void FnPrint

void FnInput(int* PInputY, int* PInputX)
{
	while (true)
	{
		cin >> *PInputY >> *PInputX;

		if ((*PInputY == 0) || (*PInputX == 0))
		{
			cout << "������ ũ��� 0���� Ŀ�� �մϴ�." << endl;
		}
		else
		{
			break;
		}

	}

}//END - void FnInput

int main()
{

	int Array2DInt[4][5]
		= {
			3,5,4,2,5,
			3,3,3,2,1,
			3,2,6,7,8,
			9,1,1,3,2
	};

	int InputY = 0; // (< 5)
	int InputX = 0; // (< 6)

	int MaxSumY = 0;
	int MaxSumX = 0;

	FnInput(&InputY, &InputX);

	FnChkMaxSumPos(Array2DInt, &InputY, &InputX, &MaxSumY, &MaxSumX);

	FnPrint(&MaxSumY, &MaxSumX);

	return 0;
}