#include <iostream>
using namespace std;

struct Postion
{
	int Y;
	int X;
};

enum class ERightLeft
{
	R,
	Middle,
	L
};

enum class ETopBottom
{
	Top,
	Middle,
	Bottom
};

void FnSetYX(int* IdxY, int* IdxX, ERightLeft RL, ETopBottom TB)
{
	int Y = *IdxY;
	int X = *IdxX;

	if (RL == ERightLeft::R)
	{
		*IdxX = X + 1;
	}
	else if (RL == ERightLeft::L)
	{
		*IdxX = X - 1;
	}
	else if (RL == ERightLeft::Middle)
	{
		*IdxX = X;
	}

	if (TB == ETopBottom::Top)
	{
		*IdxY = Y - 1;
	}
	else if (TB == ETopBottom::Bottom)
	{
		*IdxY = Y + 1;
	}
	else if (TB == ETopBottom::Middle)
	{
		*IdxY = Y;
	}

}//END -void FnSetYX

bool FnChkValid_RL(ERightLeft RL, int* IdxX)
{
	bool ReturnFlag = 0;

	int X = *IdxX;

	if (RL == ERightLeft::R)
	{
		if (X + 1 < 5)
		{
			ReturnFlag = 1;
		}
	}
	else if (RL == ERightLeft::L)
	{
		if (X - 1 >= 0)
		{
			ReturnFlag = 1;
		}
	}
	else if (RL == ERightLeft::Middle)
	{
		if ((X - 1 >= 0) || (X + 1 < 5))
		{
			ReturnFlag = 1;
		}
	}

	return ReturnFlag;
}//END - bool FnChkValid_RL

bool FnChkValid_TB(ETopBottom TB, int* IdxY)
{
	bool ReturnFlag = 0;

	int Y = *IdxY;

	if (TB == ETopBottom::Top)
	{
		if (Y - 1 >= 0)
		{
			ReturnFlag = 1;
		}
	}
	else if (TB == ETopBottom::Bottom)
	{
		if (Y + 1 < 4)
		{
			ReturnFlag = 1;
		}
	}
	else if (TB == ETopBottom::Middle)
	{
		if ((Y - 1 >= 0) || (Y + 1 < 4))
		{
			ReturnFlag = 1;
		}
	}

	return ReturnFlag;

}//END - bool FnChkValid_TB

void FnSetValue(char PArray[4][5], int* IdxY, int* IdxX, ERightLeft RL, ETopBottom TB)
{
	/*
		[y-1][x-1]	[y-1][x]	[y-1][x+1]
		[y][x-1]				[y][x+1]
		[y+1][x-1]	[y+1][x]	[y+1][x+1]

	*/

	int Y = *IdxY;
	int X = *IdxX;

	bool Chk_RL = FnChkValid_RL(RL, IdxX);
	bool Chk_Top = FnChkValid_TB(TB, IdxY);

	if (Chk_RL && Chk_Top)
	{
		FnSetYX(&Y, &X, RL, TB);
		PArray[Y][X] = '#';
	}

}//END - int FnGetValue

void FnBomb(char PArray[4][5], int* IdxY, int* IdxX)
{
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::R, ETopBottom::Top);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::R, ETopBottom::Middle);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::R, ETopBottom::Bottom);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::Middle, ETopBottom::Bottom);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::L, ETopBottom::Bottom);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::L, ETopBottom::Middle);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::L, ETopBottom::Top);
	FnSetValue(PArray, IdxY, IdxX, ERightLeft::Middle, ETopBottom::Top);

}//END - int sum

void FnDraw(char PArray[4][5])
{
	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 5; IdxX++)
		{
			cout << PArray[IdxY][IdxX] << " ";
		}
		cout << endl;
	}
}//END - void FnDraw

void Do(char PArray[4][5])
{
	Postion First = {};
	Postion Second = {};

	cin >> First.Y >> First.X;
	cin >> Second.Y >> Second.X;

	FnBomb(PArray, &(First.Y), &(First.X));

	FnBomb(PArray, &(Second.Y), &(Second.X));

	FnDraw(PArray);

}//END - void Do


int main()
{
	char GroundArray[4][5] = {};

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 5; IdxX++)
		{
			GroundArray[IdxY][IdxX] = '_';
		}
	}

	Do(GroundArray);

	return 0;
}
