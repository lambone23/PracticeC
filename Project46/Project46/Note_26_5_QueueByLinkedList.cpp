#include <iostream>
using namespace std;

struct Node
{
	char Data = ' ';
	Node* Prev = nullptr;
	Node* Next = nullptr;
};

Node* g_Head = nullptr;
Node* g_Tail = nullptr;

char* g_InArrChar = nullptr;

void FnAddNode(char InData)
{
	if (g_Head == nullptr)
	{
		Node* AddNode = new Node;

		AddNode->Data = (char)InData;
		AddNode->Prev = nullptr;
		AddNode->Next = nullptr;

		g_Head = AddNode;
		g_Tail = AddNode;
	}
	else
	{
		Node* LastNode = g_Tail;

		LastNode->Next = new Node;
		LastNode->Next->Data = InData;
		LastNode->Next->Prev = LastNode;
		LastNode->Next->Next = nullptr;

		g_Tail = LastNode->Next;
	}
}

void FnDeleteNode_Temporary(int Level, int LimitRepeatCnt)
{
	if (Level == LimitRepeatCnt)
	{
		return;
	}

	Node* DeleteNode = g_Head;

	g_Head = DeleteNode->Next;
	g_Head->Prev = nullptr;

	DeleteNode->Prev = nullptr;
	DeleteNode->Next = nullptr;

	delete DeleteNode;
	DeleteNode = nullptr;

	FnDeleteNode_Temporary(Level + 1, LimitRepeatCnt);
}

void FnDeleteNode_complete()
{
	while (true)
	{
		Node* DeleteNode = g_Tail;

		g_Tail = DeleteNode->Prev;

		delete DeleteNode;
		DeleteNode = nullptr;

		if (g_Tail->Prev == nullptr)
		{
			break;
		}
	}
}

void FnPrintAllNode()
{
	Node* PrintNode = g_Head;

	while (PrintNode->Next != nullptr)
	{
		cout << PrintNode->Data << " ";
		PrintNode = PrintNode->Next;
	}

	cout << PrintNode->Data << endl; // g_Tail
}

void FnInput(int* InArrInt)
{
	cin >> InArrInt[0] >> InArrInt[1];

	g_InArrChar = new char[InArrInt[0] + 1];

	//cin >> g_InArrChar;

	for (int Idx = 0; Idx < InArrInt[0]; Idx++)
	{
		cin >> g_InArrChar[Idx];
	}

	g_InArrChar[InArrInt[0]] = '\0';
}

int main()
{
	int InArrInt[2] = {};

	FnInput(InArrInt);

	for (int Idx = 0; Idx < (InArrInt[0]); Idx++)
	{
		FnAddNode((char)(g_InArrChar[Idx]));
	}

	FnDeleteNode_Temporary(0, InArrInt[1]);

	FnPrintAllNode();

	FnDeleteNode_complete();

	return 0;
}
