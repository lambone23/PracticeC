#include <iostream>
using namespace std;

struct Node
{
	char Data = ' ';
	Node* Next = nullptr;
};

void FnInput(int* PInData, char* PNodeData)
{
	int Numb = 0;
	bool FlagZ = 0;

	for (int Idx = 0; Idx < 4; Idx++)
	{
		if ('Z' == (char)((*PInData + Idx) - 11 + (int)'A'))
		{//[33: W][34: X][35: Y][36: Z][11: A][12: B][13: C]

			PNodeData[Idx] = (char)((*PInData + Numb) - 11 + (int)'A');
			Numb = 0;
			FlagZ = 1;
		}
		else if (!FlagZ)
		{
			PNodeData[Idx] = (char)((*PInData + Numb) - 11 + (int)'A');
			Numb++;
		}
		else if (FlagZ)
		{// [11: A][12: B][13: C] ... [36: Z]

			PNodeData[Idx] = (char)((11 + Numb) - 11 + (int)'A');
			Numb++;
		}
	}

	PNodeData[4] = '\0';

	//cout << PNodeData;
}

int main()
{
	int InputValue = 0;

	cin >> InputValue;

	char NodeData[5] = {};

	FnInput(&InputValue, NodeData);

	Node* head = new Node;

	head->Next = new Node;
	head->Next->Data = NodeData[0];

	head->Next->Next = new Node;
	head->Next->Next->Data = NodeData[1];

	head->Next->Next->Next = new Node;
	head->Next->Next->Next->Data = NodeData[2];

	head->Next->Next->Next->Next = new Node;
	head->Next->Next->Next->Next->Data = NodeData[3];

	Node* Head = head;

	for (int i = 0; i < 4; i++)
	{
		cout << Head->Next->Data;
		Head = Head->Next;
	}

	delete head->Next->Next->Next->Next;
	delete head->Next->Next->Next;
	delete head->Next->Next;
	delete head->Next;
	delete head;

	return 0;
}