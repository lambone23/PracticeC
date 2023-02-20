#include <iostream>
using namespace std;

struct Node
{
	int Data = 0;
	Node* Prev = nullptr;
	Node* Next = nullptr;
};

Node* g_Head = nullptr;
Node* g_Tail = nullptr;

void FnEnqueue(int InData)
{
	if (g_Head == nullptr)
	{
		Node* AddNode = new Node;

		AddNode->Data = InData;
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

void FnDequeue()
{
	Node* DeleteNode = g_Head;

	if (DeleteNode->Next == nullptr)
	{
		g_Tail = nullptr;
		g_Head = nullptr;
	}
	else
	{
		g_Head = DeleteNode->Next;
		g_Head->Prev = nullptr;

		DeleteNode->Prev = nullptr;
		DeleteNode->Next = nullptr;

		delete DeleteNode;
		DeleteNode = nullptr;
	}
}

void FnDeleteNode_complete()
{
	while (true)
	{
		if (g_Tail != nullptr)
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
		else
		{
			delete g_Tail;
			g_Tail = nullptr;

			delete g_Head;
			g_Head = nullptr;
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

int main()
{
	int Cnt = 0;

	cin >> Cnt;

	char* InArrED = nullptr;
	int* InArrData = nullptr;

	InArrED = new char[Cnt];
	InArrData = new int[Cnt];

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		cin >> InArrED[Idx];
		cin >> InArrData[Idx];
	}

	bool FlagValid = 0;
	int CntNode = 0;

	for (int Idx = 0; Idx < Cnt; Idx++)
	{
		if ('E' == InArrED[Idx])
		{
			++CntNode;

			if ((0 <= CntNode) && (4 >= CntNode))
			{
				FnEnqueue(InArrData[Idx]);
				FlagValid = 1;
			}
			else
			{
				FlagValid = 0;
				break;
			}

		}
		else
		{
			--CntNode;

			if ((0 <= CntNode) && (4 >= CntNode))
			{
				FnDequeue();
				FlagValid = 1;
			}
			else
			{
				FlagValid = 0;
				break;
			}
		}
	}

	if (FlagValid)
	{
		FnPrintAllNode();
	}
	else
	{
		cout << "Error";
	}

	FnDeleteNode_complete();

	delete[] InArrED;
	delete[] InArrData;

	return 0;
}

