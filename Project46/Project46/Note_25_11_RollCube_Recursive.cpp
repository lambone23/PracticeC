#include <iostream>
using namespace std;

void FnPrint(int PCube[3][3])
{
	cout << endl;

	for (int IdxY = 0; IdxY < 3; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			if (0 == PCube[IdxY][IdxX])
			{
				cout << "_" << " ";
			}
			else
			{
				cout << PCube[IdxY][IdxX] << " ";
			}
		}
		cout << endl;
	}

	cout << endl;
}

void FnRoll(int Level, int* Cnt, int PCube[3][3], int PResult[3][3])
{
	/*

	(0,0) -> (0,2)
	(0,1) -> (1,2) [5]
	(0,2) -> (2,2) [4]

	(1,0) -> (0,1) [3]
	(1,1) -> (1,1)
	(1,2) -> (2,1)

	(2,0) -> (0,0)
	(2,1) -> (1,0)
	(2,2) -> (2,0) [1]

	*/

	if (Level == *Cnt)
	{
		return;
	}

	for (int Y_Cube = 0; Y_Cube < 3; Y_Cube++)
	{
		for (int X_Cube = 0; X_Cube < 3; X_Cube++)
		{
			PResult[X_Cube][2 - Y_Cube] = PCube[Y_Cube][X_Cube];
		}
	}

	for (int Y_Cube = 0; Y_Cube < 3; Y_Cube++)
	{
		for (int X_Cube = 0; X_Cube < 3; X_Cube++)
		{
			PCube[Y_Cube][X_Cube] = PResult[Y_Cube][X_Cube];
		}
	}

	FnRoll(Level + 1, Cnt, PCube, PResult);

}//END - void FnRoll

int main()
{
	int Cube[3][3]
		= {
				0,	5,	4,
				3,	0,	0,
				0,	0,	1
	};

	int Result[3][3]
		= {
				0,	5,	4,
				3,	0,	0,
				0,	0,	1
	};

	FnPrint(Cube);

	int Cnt = 0;

	cin >> Cnt;

	FnRoll(0, &Cnt, Cube, Result);

	FnPrint(Cube);

	return 0;
}