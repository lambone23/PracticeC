#include <iostream>
using namespace std;

struct Node
{
	int x = 0;
	char y = ' ';
};

int main()
{
	Node* queue = nullptr;

	int Cnt = 0;

	cin >> Cnt;

	queue = new Node[Cnt];

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		cin >> queue[Idx].x;
		cin >> queue[Idx].y;
	}

	// pop
	if (Cnt == 1)
	{
		cout << queue[0].x << " " << queue[0].y << endl;

		queue[0].x = 0;
		queue[0].y = 0;
	}
	else
	{
		cout << endl;

		for (int PopAllCnt = 0; PopAllCnt < Cnt; PopAllCnt++)
		{
			cout << queue[0].x << " " << queue[0].y << endl;

			queue[0].x = 0;
			queue[0].y = 0;

			for (int Idx = 0; Idx < (Cnt - 1); Idx++)
			{
				queue[Idx].x = queue[Idx + 1].x;
				queue[Idx].y = queue[Idx + 1].y;
			}

			if (0 == PopAllCnt)
			{
				queue[Cnt - 1].x = 0;
				queue[Cnt - 1].y = 0;
			}
		}
	}

	delete[] queue;

	return 0;
}
