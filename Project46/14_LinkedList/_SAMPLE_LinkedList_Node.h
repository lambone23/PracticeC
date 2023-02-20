#pragma once
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
	char Data = ' ';
	Node* Prev = nullptr;
	Node* Next = nullptr;
};

Node *g_Head = nullptr;
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


void FnEnqueue(char InData)
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

// 노드 주소값 반환
// 노드의 데이터 값 기준으로 특정 노드 찾기
Node* FnFindNodeByData(char InData)
{
	Node* ReturnNode = nullptr;

	if (InData == g_Head->Data)
	{
		ReturnNode = g_Head;
	}
	else if (InData == g_Tail->Data)
	{
		ReturnNode = g_Tail;
	}
	else
	{
		Node* FindNode = g_Head;

		while (FindNode != nullptr)
		{
			if (InData == FindNode->Data)
			{
				ReturnNode = FindNode;
				break;
			}

			FindNode = FindNode->Next;
		}

		if (FindNode == nullptr)
		{
			cout << endl;
			cout << "***** ERROR *****" << endl;
			cout << "FnFindNodeByData" << endl;
			cout << "입력 데이터와 일치하는 노드를 찾을 수 없음" << endl;
		}
	}

	return ReturnNode;

}//END - Node* FnFindNodeByData

// 삭제
// 노드의 데이터 값 기준으로 특정 노드 삭제
void FnDeleteNodeByData(char InData)
{
	//노드 데이터 값 기준으로 삭제할 노드 주소 찾기
	Node* DeleteNode = FnFindNodeByData(InData);

	if (DeleteNode->Next != nullptr)
	{
		Node* PrevNode = DeleteNode->Prev;
		Node* NextNode = DeleteNode->Next;

		//삭제할 노드 기준 앞과 뒤끼리 연결
		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;
	}
	else
	{// 삭제하려는 노드가 맨끝 노드인 경우
		Node* PrevNode = DeleteNode->Prev;

		//삭제할 노드 기준 뒤는 없음으로 처리
		PrevNode->Next = nullptr;

		//맨끝 노드 주소 갱신
		g_Tail = PrevNode;
	}

	delete DeleteNode;
	DeleteNode = nullptr;

}//END - void FnDeleteNodeByData

// 삽입
/*
[입력값]
	1. 추가할 노드의 데이터 값
	2. 추가할 노드의 이전 데이터

	어떤 노드 뒤에 이어서 추가할지
	위치를 선정하기 위한 기준으로
	이전 노드 데이터 값을
	추가할 노드의 데이터 값과 함께 입력받음.
*/
void FnInsertNode(char InData, char PrevData)
{
	Node* PrevNode = FnFindNodeByData(PrevData);

	if (PrevNode == g_Tail)
	{
		/*
		이전 노드가 맨끝 노드인 경우
		또는 이전노드 데이터 값과 일치하는 이전노드가 없는 경우
		*/

		Node* AddNode = new Node();
		AddNode->Data = InData;
		AddNode->Next = nullptr;
		AddNode->Prev = PrevNode;

		// 기존의 이전 노드 정보 갱신
		PrevNode->Next = AddNode;

		//맨끝 노드 주소 갱신
		g_Tail = AddNode;
	}
	else
	{
		Node* NextNode = PrevNode->Next;

		Node* AddNode = new Node();
		AddNode->Data = InData;
		AddNode->Next = NextNode;
		AddNode->Prev = PrevNode;

		// 기존의 이전 노드와 이후 노드 정보 갱신
		PrevNode->Next = AddNode;
		NextNode->Prev = AddNode;
	}

}//END - void FnInsertNode

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
