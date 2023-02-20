#include <iostream>
using namespace std;

void FnChkCntPattern(char Pmap[3][4], char Ppattern[2][2], int IdxY, int IdxX, int* Cnt)
{
	/*
		[Y][X] pattern[0][0]		[Y][X+1] pattern[0][1]
		[Y+1][X] pattern[1][0]		[Y+1][X+1] pattern[1][1]
	*/

	int Direct[3][2]
		= {
			{0, 1},
			{1, 1},
			{1, 0}
	};

	bool FlagFind = 0;
	char Standard = Pmap[IdxY][IdxX];

	if (Standard == Ppattern[0][0])
	{
		for (int i = 0; i < 3; i++)
		{
			int PatternY = Direct[i][0];
			int PatternX = Direct[i][1];
			int MapY = IdxY + PatternY;
			int MapX = IdxX + PatternX;

			if (Pmap[MapY][MapX] == Ppattern[PatternY][PatternX])
			{
				FlagFind = 1;
			}
			else
			{
				FlagFind = 0;
				break;
			}

		}
	}
	else
	{
		FlagFind = 0;
	}

	if (FlagFind)
	{
		++(*Cnt);
	}

}//END - void FnChkCntPattern

void FnChkPattern(char Pmap[3][4], char Ppattern[2][2], int* Cnt)
{
	for (int IdxY = 0; IdxY < 2; IdxY++)
	{// map - Y
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{// map - X

			// 패턴 찾기 (다이렉트 기법 적용)
			FnChkCntPattern(Pmap, Ppattern, IdxY, IdxX, Cnt);

		}
	}

}//END - void FnChkPattern

void FnMakePatternArray(char Ppattern[2][2])
{
	for (int IdxY = 0; IdxY < 2; IdxY++)
	{
		for (int IdxX = 0; IdxX < 2; IdxX++)
		{
			cin >> Ppattern[IdxY][IdxX];
		}
	}

}//END = void FnMakePatternArray

void FnPrintResult(int* Cnt)
{
	if (*Cnt != 0)
	{
		cout << "발견(" << *Cnt << ")개";
	}
	else
	{
		cout << "미발견";
	}

}//END - void FnPrintResult

int main()
{
	char map[3][4]
		= {
			'A', 'B', 'G', 'K',
			'T', 'T', 'A', 'B',
			'A', 'C', 'C', 'D'
	};

	char pattern[2][2] = {};

	FnMakePatternArray(pattern);

	int Cnt = 0;

	FnChkPattern(map, pattern, &Cnt);

	FnPrintResult(&Cnt);

	return 0;
}
