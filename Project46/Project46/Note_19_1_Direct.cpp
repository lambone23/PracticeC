#include <iostream>
using namespace std;

enum class EDirections
{
	R,
	L,
	T,
	B
};

enum class EIdxX
{
	Start,
	Middle,
	Last
};

enum class EIdxY
{
	Top,
	Middle,
	Bottom
};


struct Directions
{
	int R;
	int L;
	int T;
	int B;
};

struct Position
{
	int Y;
	int X;
};

void FnSetPos(int* PY, int* PX, EDirections EDirect)
{
	int InY = *PY;
	int InX = *PX;

	int ResultY = -999;
	int ResultX = -999;

	if (EDirect == EDirections::R)
	{
		ResultY = InY;
		ResultX = InX + 1;
	}
	else if (EDirect == EDirections::L)
	{
		ResultY = InY;
		ResultX = InX - 1;
	}
	else if (EDirect == EDirections::T)
	{
		ResultY = InY - 1;
		ResultX = InX;
	}
	else if (EDirect == EDirections::B)
	{
		ResultY = InY + 1;
		ResultX = InX;
	}

	*PY = ResultY;
	*PX = ResultX;

}//END - void SetPos

int FnGetValue(int PArray[3][3], int* InY, int* InX, EDirections EDirect)
{
	//=================================
	// 입력부 셋팅
	//=================================
	int ReturnValue = 0;

	Position Pos = {};

	Pos.Y = *InY;
	Pos.X = *InX;

	bool ChkInvalid = 0;

	//=================================
	// 처리
	//=================================

	if (EDirect == EDirections::R)
	{// [Y][X + 1];

		if (Pos.X == (int)EIdxX::Last)
		{
			ChkInvalid = 1;
		}
		else
		{
			FnSetPos(&(Pos.Y), &(Pos.X), EDirections::R);
		}
	}
	else if (EDirect == EDirections::L)
	{// [Y][X - 1];

		if (Pos.X == (int)EIdxX::Start)
		{
			ChkInvalid = 1;
		}
		else
		{
			FnSetPos(&(Pos.Y), &(Pos.X), EDirections::L);
		}
	}
	else if (EDirect == EDirections::T)
	{// [Y - 1][X];

		if (Pos.Y == (int)EIdxY::Top)
		{
			ChkInvalid = 1;
		}
		else
		{
			FnSetPos(&(Pos.Y), &(Pos.X), EDirections::T);
		}
	}
	else if (EDirect == EDirections::B)
	{// [Y + 1][X];

		if (Pos.Y == (int)EIdxY::Bottom)
		{
			ChkInvalid = 1;
		}
		else
		{
			FnSetPos(&(Pos.Y), &(Pos.X), EDirections::B);
		}
	}

	if (ChkInvalid)
	{
		ReturnValue = 0;
	}
	else
	{
		ReturnValue = PArray[Pos.Y][Pos.X];
	}

	//=================================
	// 결과
	//=================================
	return ReturnValue;

}//END -int FnGetValue

void FnGetSum(int* PSum, int PArray[3][3], int* InY, int* InX)
{
	Directions Direct4 = {};

	Direct4.R = FnGetValue(PArray, InY, InX, EDirections::R);
	Direct4.L = FnGetValue(PArray, InY, InX, EDirections::L);
	Direct4.T = FnGetValue(PArray, InY, InX, EDirections::T);
	Direct4.B = FnGetValue(PArray, InY, InX, EDirections::B);

	*PSum = Direct4.R + Direct4.L + Direct4.T + Direct4.B;

}//END - int FnGetSum

void FnInput(int* InY, int* InX)
{
	while (true)
	{
		cin >> *InY >> *InX;

		if (
			(0 <= *InY) && (2 >= *InY) &&
			(0 <= *InX) && (2 >= *InX)
			)
		{
			break;
		}
		else
		{
			cout << "index 유효값은 0 ~ 2" << endl;
		}
	}
}//END - void FnInput

void Do()
{
	int Array2DInt[3][3]
		= {
			3,	5,	4,
			1,	1,	2,
			1,	3,	9
	};

	int InputY = 0;
	int InputX = 0;
	int Sum = 0;

	FnInput(&InputY, &InputX);

	FnGetSum(&Sum, Array2DInt, &InputY, &InputX);

	cout << Sum;

}//END - void Do()

int main()
{
	Do();

	return 0;
}