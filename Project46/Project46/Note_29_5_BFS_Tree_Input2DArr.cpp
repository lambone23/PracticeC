/*

입력 예제
0 1 0 1 1 0
0 0 1 0 0 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

출력 결과
1 3 5

*/


#include <iostream>
using namespace std;

struct Node
{
	int Numb;
	int Level;
};

int main()
{
	int NodeArr[6][6] = {};

	for (int IdxY = 0; IdxY < 6; IdxY++)
	{
		for (int IdxX = 0; IdxX < 6; IdxX++)
		{
			cin >> NodeArr[IdxY][IdxX];
		}
	}

	Node Queue[6] = { {0,0} };

	int Head = 0;
	int Tail = 1;

	while (Head != Tail)
	{
		//cout << "Head : " << Head << ", Tail : " << Tail << endl;

		Node Now = Queue[Head];

		if (Now.Numb % 2 != 0)
		{
			cout << Now.Numb << " ";
		}

		for (int IdxX = 0; IdxX < 6; IdxX++)
		{
			if (NodeArr[Now.Numb][IdxX] == 1)
			{
				//cout << "IdxX : " << IdxX << ", Now.Level : " << Now.Level << endl;

				Queue[Tail++] = { IdxX , Now.Level + 1 };
			}
		}

		Head++;
	}

	//for (int Idx = 0; Idx < 6; Idx++)
	//{
	//	if ((Queue[Idx].Numb % 2 != 0) || (Queue[Idx].Numb == 1))
	//	{
	//		cout << Queue[Idx].Numb << " ";
	//	}
	//}

	return 0;
}
