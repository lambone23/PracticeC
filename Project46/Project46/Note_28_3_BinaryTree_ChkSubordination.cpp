#include <iostream>
using namespace std;

int main()
{
	char BinaryTree[10] = "#ADFZCGQH";

	/*

						A[1]

					D[2]	F[3]

			Z[4]	C[5]	G[6]	Q[7]

		K[8]

		=======================================
		A[X] :	D[X * 2 + 0]	F[X * 2 + 1]
		D[X] :	Z[X * 2 + 0]	C[X * 2 + 1]

	*/

	char InChar1 = ' ';
	char InChar2 = ' ';

	int Idx1 = 0;
	int Idx2 = 0;

	cin >> InChar1 >> InChar2;

	for (int Idx = 1; Idx < 10; Idx++)
	{
		if (BinaryTree[Idx] == InChar1)
		{
			Idx1 = Idx;
		}

		if (BinaryTree[Idx] == InChar2)
		{
			Idx2 = Idx;
		}
	}

	if (
		(Idx1 == (Idx2 * 2)) || (Idx1 == (Idx2 * 2 + 1)) ||	// [P: Idx1],[C: Idx2]
		(Idx2 == (Idx1 * 2)) || (Idx2 == (Idx1 * 2 + 1))	// [P: Idx1],[C: Idx2]
		)
	{
		cout << "부모자식관계";
	}
	else
	{
		cout << "아님";
	}

	return 0;
}
