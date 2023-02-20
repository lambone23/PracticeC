
/*

0년  =>  1마리
1년  =>  3마리 + 1마리 = 4마리
2년  =>  9마리 + 3마리 + 1마리 = 13마리


입력 예제

1
출력 결과
4

*/



/*

#include <iostream>
using namespace std;

void FnGetCnt(int *PSum, int *PLastCnt)
{
	*PSum = (*PSum) + (*PLastCnt) * 3;
	(*PLastCnt) = (*PLastCnt) * 3;
}

int main()
{
	int Sum = 1;
	int LastCnt = 1;

	int Year = 0;

	cin >> Year;

	if (Year == 0)
	{
		Sum = 1;
	}
	else
	{
		for (int RepaetCnt = 0; RepaetCnt < Year; RepaetCnt++)
		{
			FnGetCnt(&Sum, &LastCnt);
		}
	}

	cout << Sum;

	return 0;
}

*/


#include <iostream>
using namespace std;

// Queue By LinkedList

#define EtoI_F (int)(EPrintOrder::Front)
#define EtoI_B (int)(EPrintOrder::Back)

enum class EPrintOrder
{
	Front,
	Back
};

struct Node
{
	int Data = ' ';
	Node* Prev = nullptr;
	Node* Next = nullptr;
};

Node* g_Head = nullptr;
Node* g_Tail = nullptr;

template <typename T>
void FnPrintQueue(T EInData)
{
	int Data = (int)EInData;

	if (EtoI_F == Data)
	{
		Node* PrintNode = g_Head;

		while (PrintNode != nullptr)
		{
			cout << PrintNode->Data << " ";

			PrintNode = PrintNode->Next;
		}
	}
	else if (EtoI_B == Data)
	{
		Node* PrintNode = g_Tail;

		while (PrintNode != nullptr)
		{
			cout << PrintNode->Data << " ";

			PrintNode = PrintNode->Prev;
		}
	}

	cout << endl;
}//END - void FnPrintQueue


void FnGetSumAllNodeData(int* PSum)
{
	Node* PrintNode = g_Head;

	while (PrintNode != nullptr)
	{
		*PSum = (*PSum) + PrintNode->Data;

		PrintNode = PrintNode->Next;
	}

}//END - void FnPrintQueue

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
		Node* ExistedLastNode = g_Tail;
		ExistedLastNode->Next = new Node;

		Node* AddNode = ExistedLastNode->Next;
		AddNode->Data = InData;
		AddNode->Prev = ExistedLastNode;
		AddNode->Next = nullptr;

		g_Tail = AddNode;
	}
}//END - void FnEnqueue

void FnDequeue()
{
	Node* ExistedFirstNode = g_Head;

	if (ExistedFirstNode->Next == nullptr)
	{
		delete g_Head;
		g_Head = nullptr;
		g_Tail = nullptr;
	}
	else
	{
		g_Head = ExistedFirstNode->Next;
		g_Head->Prev = nullptr;
		ExistedFirstNode->Next = nullptr;

		delete ExistedFirstNode;
		ExistedFirstNode = nullptr;
	}
}//END -void FnDequeue

void FnDeleteNode_complete()
{
	Node* TmpLastNode = g_Tail;

	while (TmpLastNode != nullptr)
	{
		Node* DeleteNode = TmpLastNode;
		TmpLastNode = DeleteNode->Prev;

		delete DeleteNode;
		DeleteNode = nullptr;
	}
}

int main()
{
	int Cnt = 1;

	FnEnqueue(Cnt);

	int CntYear = 0;

	cin >> CntYear;

	for (int repeatCnt = 0; repeatCnt < CntYear; repeatCnt++)
	{
		Cnt = Cnt * 3;
		FnEnqueue(Cnt);
	}

	//FnPrintQueue(EPrintOrder::Front);

	int Sum = 0;

	FnGetSumAllNodeData(&Sum);

	cout << Sum;

	FnDeleteNode_complete();

	return 0;
}
