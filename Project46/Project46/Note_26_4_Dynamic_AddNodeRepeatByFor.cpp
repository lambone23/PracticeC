#include <iostream>
using namespace std;

struct Node
{
	char a = ' ';
	int b = 0;
	Node* p = nullptr;
};

int main()
{// TODO : 悼利且寸 秦力 贸府

	int n = 0;

	cin >> n;

	Node* Head = new Node;
	Node* TmpHead = Head;

	bool FlagZ = 0;
	int Numb = 0;

	for (int Idx = 0; Idx < n; Idx++)
	{
		Node* AddNode = new Node;

		TmpHead->p = AddNode;

		if ((!FlagZ) && ('Z' == ('A' + Idx)))
		{// [# 2]
			AddNode->a = (char)('A' + Idx);
			FlagZ = 1;
			Numb = 0;
		}
		else if (!FlagZ)
		{// [# 1]
			AddNode->a = (char)('A' + Idx);
		}
		else if (FlagZ && ('Z' == ('A' + Numb)))
		{// [# 4][# 6][# 8]
			AddNode->a = (char)('A' + Numb);
			Numb = 0;
		}
		else if (FlagZ)
		{// [# 3][# 5][# 7]
			AddNode->a = (char)('A' + Numb);
			++Numb;
		}

		AddNode->b = Idx + 1;
		AddNode->p = nullptr;

		TmpHead = TmpHead->p;
	}

	TmpHead = Head;

	for (int Idx = 0; Idx < n; Idx++)
	{
		cout << TmpHead->p->a << " ";
		TmpHead = TmpHead->p;
	}

	cout << endl;

	TmpHead = Head;

	while (TmpHead->p != nullptr)
	{
		cout << TmpHead->p->b << " ";
		TmpHead = TmpHead->p;
	}

	return 0;
}