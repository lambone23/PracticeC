#include <iostream>
using namespace std;

int main()
{
	int relation[5][5]
		= {
		//  A  B  C  D  E [X]|[Y]
			0, 1, 7, 2, 0,	// A 
			1, 0, 8, 0, 5,	// B
			7, 8, 0, 3, 6,	// C
			2, 0, 3, 0, 0,	// D
			0, 5, 6, 0, 0	// E
	};

	/*
		//  A  B  C  D  E [X]|[Y]
			_, *, *, *, *,	// A	[0, 1][0, 2][0, 3][0, 4]
			_, _, *, *, *,	// B		  [1, 2][1, 3][1, 4]
			_, _, _, *, *,	// C				[2, 3][2, 4]
			_, _, _, _, *,	// D					  [3, 4]
			_, _, _, _, _	// E
	*/

	int Start_X = 1;

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = Start_X; IdxX <= 4; IdxX++)
		{
			if ((IdxY != IdxX) && (0 != relation[IdxY][IdxX]))
			{
				cout << (char)('A' + IdxY) << " ";
				cout << (char)('A' + IdxX) << " ";
				cout << relation[IdxY][IdxX] << endl;
			}
		}

		++(Start_X);
	}

	return 0;
}

