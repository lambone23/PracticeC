#include <iostream>
using namespace std;

struct Postion
{
	int Y;
	int X;
};

void FnPrint(int PBoard[4][4])
{
	cout << endl;
	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			if (PBoard[IdxY][IdxX] != '\0')
			{
				cout << PBoard[IdxY][IdxX] << " ";
			}
			else
			{
				cout << "_ ";
			}
		}

		cout << endl;
	}
	cout << endl;
}

void FnRecursive(int Level, int PBoard[4][4])
{
	// Àç±Í ÀÛ¾÷ Áß´Ü ¿©ºÎ È®ÀÎ
	// [# 1] : ºóÄ­ÀÌ Á¸ÀçÇÏ¸é Àç±Í ½ÇÇà
	// [# 2] : ÀüºÎ ºóÄ­ÀÌ ¾Æ´ÔÀ» È®ÀÎÇÏ¸é Àç±Í Á¾·á
	bool FlagDoRecursive = 0;

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			if (PBoard[IdxY][IdxX] != '\0')
			{
				FlagDoRecursive = 0;
			}
			else
			{
				FlagDoRecursive = 1; // ºóÄ­ÀÌ Á¸ÀçÇÔÀ» È®ÀÎ
				break;
			}
		}

		if (FlagDoRecursive)
		{
			break;
		}
	}

	if (!FlagDoRecursive)
	{// [# 2]
		return;
	}

	// [# 1] 
	int Direct[4][2]
		= {
			{-1, 0},
			{0, 1},
			{1, 0},
			{0, -1},

	};

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 4; IdxX++)
		{
			if (PBoard[IdxY][IdxX] == Level + 1)
			{
				for (int i = 0; i < 4; i++)
				{
					int DirectY = IdxY + Direct[i][0];
					int DirectX = IdxX + Direct[i][1];

					if (
						(DirectY >= 0) && (DirectY <= 3) &&
						(DirectX >= 0) && (DirectX <= 3) &&
						(PBoard[DirectY][DirectX] == '\0')
						)
					{
						PBoard[DirectY][DirectX] = Level + 2;
					}
				}
			}
		}
	}

	FnRecursive(Level + 1, PBoard);
}//END -void FnRecursive

int main()
{
	int Board[4][4] = {};

	Postion In = {};

	// ÀÔ·Â
	cin >> In.Y >> In.X;

	Board[In.Y][In.X] = 1;

	FnRecursive(0, Board);

	FnPrint(Board);

	return 0;
}

