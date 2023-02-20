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

// ��� �ּҰ� ��ȯ
// ����� ������ �� �������� Ư�� ��� ã��
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
			cout << "�Է� �����Ϳ� ��ġ�ϴ� ��带 ã�� �� ����" << endl;
		}
	}

	return ReturnNode;

}//END - Node* FnFindNodeByData

// ����
// ����� ������ �� �������� Ư�� ��� ����
void FnDeleteNodeByData(char InData)
{
	//��� ������ �� �������� ������ ��� �ּ� ã��
	Node* DeleteNode = FnFindNodeByData(InData);

	if (DeleteNode->Next != nullptr)
	{
		Node* PrevNode = DeleteNode->Prev;
		Node* NextNode = DeleteNode->Next;

		//������ ��� ���� �հ� �ڳ��� ����
		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;
	}
	else
	{// �����Ϸ��� ��尡 �ǳ� ����� ���
		Node* PrevNode = DeleteNode->Prev;

		//������ ��� ���� �ڴ� �������� ó��
		PrevNode->Next = nullptr;

		//�ǳ� ��� �ּ� ����
		g_Tail = PrevNode;
	}

	delete DeleteNode;
	DeleteNode = nullptr;

}//END - void FnDeleteNodeByData

// ����
/*
[�Է°�]
	1. �߰��� ����� ������ ��
	2. �߰��� ����� ���� ������

	� ��� �ڿ� �̾ �߰�����
	��ġ�� �����ϱ� ���� ��������
	���� ��� ������ ����
	�߰��� ����� ������ ���� �Բ� �Է¹���.
*/
void FnInsertNode(char InData, char PrevData)
{
	Node* PrevNode = FnFindNodeByData(PrevData);

	if (PrevNode == g_Tail)
	{
		/*
		���� ��尡 �ǳ� ����� ���
		�Ǵ� ������� ������ ���� ��ġ�ϴ� ������尡 ���� ���
		*/

		Node* AddNode = new Node();
		AddNode->Data = InData;
		AddNode->Next = nullptr;
		AddNode->Prev = PrevNode;

		// ������ ���� ��� ���� ����
		PrevNode->Next = AddNode;

		//�ǳ� ��� �ּ� ����
		g_Tail = AddNode;
	}
	else
	{
		Node* NextNode = PrevNode->Next;

		Node* AddNode = new Node();
		AddNode->Data = InData;
		AddNode->Next = NextNode;
		AddNode->Prev = PrevNode;

		// ������ ���� ���� ���� ��� ���� ����
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
