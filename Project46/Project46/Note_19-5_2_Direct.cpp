#include <iostream>
using namespace std;

bool FnChkValid(int PArray[5][4], int Y, int X)
{
	bool ReturnFlag = 0;

	/*
		LT:[Y-1][X-1]		MT:[Y-1][X]		RT:[Y-1][X+1]

		LM:[Y][X-1]			[Y][X]			RM:[Y][X+1]

		LB:[Y+1][X-1]		MB:[Y+1][X]		RB:[Y+1][X+1]

	*/

	int direct[8][2]
		= {
		// [Y]	[X]
		{-1,	+1},	// RT
		{0,		+1},	// RM
		{+1,	+1},	// RB

		{+1,	0},		// MB

		{+1,	-1},	// LB
		{0,		-1},	// LM
		{-1,	-1},	// LT

		{-1,	0}		// MT
	};

	for (int i = 0; i < 8; i++)
	{
		int ApplyDirect_Y = Y + direct[i][0];
		int ApplyDirect_X = X + direct[i][1];

		if (
			(ApplyDirect_Y >= 0) && // "0" < IdxY < 4
			(ApplyDirect_Y <= 4) && // 0 < IdxY < "4"
			(ApplyDirect_X >= 0) && // "0" < IdxX < 3
			(ApplyDirect_X <= 3)	// 0 < IdxX < "3"
			)
		{
			if (1 != PArray[ApplyDirect_Y][ApplyDirect_X])
			{
				ReturnFlag = 1;
			}
			else
			{
				ReturnFlag = 0;
			}
		}
	}

	return ReturnFlag;

}//END- bool FnChkValid


int main()
{
	int Array2DInt[5][4] = {};

	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			cin >> Array2DInt[IdxY][IdxX];
		}
	}

	//cout << endl;

	//for (int IdxY = 0; IdxY < 5; IdxY++)
	//{
	//	for (int IdxX = 0; IdxX < 4; IdxX++)
	//	{
	//		cout << Array2DInt[IdxY][IdxX] << " ";
	//	}

	//	cout << endl;
	//}

	bool FlagValid = 0;

	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			if (1 == Array2DInt[IdxY][IdxX])
			{
				FlagValid = FnChkValid(Array2DInt, IdxY, IdxX);

				cout << FlagValid << endl;

				if (!FlagValid)
				{
					break;
				}
			}
		}
	}

	if (FlagValid)
	{
		cout << "안정된 상태";
	}
	else
	{
		cout << "불안정한 상태";
	}

	return 0;
}
