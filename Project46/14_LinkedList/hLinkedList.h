#pragma once

int g = 100;

struct Node
{
	int Data;
	Node* NextAddr;
	Node* PrevAddr;
};

Node* PHeadNode = nullptr; // ��ó��
Node* PTailNode = nullptr; // �ǳ�

// ���
void PrintNodes()
{
	if (PHeadNode == nullptr)
	{
		std::cout << "����" << std::endl;
	}
	else
	{
		Node* PNode = PHeadNode;
		while (PNode->NextAddr != nullptr)
		{
			std::cout << PNode->Data << " ";
			PNode = PNode->NextAddr;
		}
		std::cout << PTailNode->Data << std::endl;
	}
}

// ����
void AddNode(int InData)
{
	g = 200;

	if (PHeadNode == nullptr)
	{// ���� ������

		// ��[�����Ҵ� �߻�] : PHeadNode
		PHeadNode = new Node();
		(*PHeadNode).Data = InData;
		(*PHeadNode).NextAddr = nullptr;
		(*PHeadNode).PrevAddr = nullptr;

		//�ǳ� ��� �ּ� ����
		PTailNode = PHeadNode;
	}
	else
	{// ���� ��� ��� �����
		Node* PLastNode = PHeadNode;
		
		while ((*PLastNode).NextAddr != nullptr)
		{// ���� ��尡 �������� �ʴ� �ǳ����� �ݺ�
			PLastNode = (*PLastNode).NextAddr;
		}

		// ���� ��尡 �������� �ʴ� ���
		// �ǳ��� ���ο� ��� �߰�

		// ��[�����Ҵ� �߻�]
		(*PLastNode).NextAddr = new Node(); 
		(*((*PLastNode).NextAddr)).PrevAddr = PLastNode;
		(*((*PLastNode).NextAddr)).Data = InData;
		(*((*PLastNode).NextAddr)).NextAddr = nullptr;
		
		//�ǳ� ��� �ּ� ����
		PTailNode = (*PLastNode).NextAddr;
	}
}//END - void AddNode(int InData)

// ��� �ּҰ� ��ȯ
// ����� ������ �� �������� Ư�� ��� ã��
Node* FindByData(int InData)
{
	if (PHeadNode->Data == InData)
	{
		return PHeadNode;
	}
	else if (PTailNode->Data == InData)
	{
		return PTailNode;
	}
	else
	{
		Node* PFindNode = PHeadNode;

		while (PFindNode->NextAddr != nullptr)
		{// ���� ��尡 �������� �ʴ� �ǳ����� �ݺ�

			if (InData == PFindNode->Data)
			{// ��带 ã�� ���
				return PFindNode;
			}

			// ã���� �ϴ� ��尡 �ƴ� ���
			// ���� ���� ����
			PFindNode = PFindNode->NextAddr;
		}
	}
}//END - Node* FindByData(int InData)

// ����
// ����� ������ �� �������� Ư�� ��� ����
void DeleteNode(int InData)
{// ����� ����

	//��� ������ �� �������� ������ ��� �ּ� ã��
	Node* PDeleteNode = FindByData(InData);

	g = 200;

	if (PDeleteNode->NextAddr != nullptr)
	{
		Node* PPrevNode = PDeleteNode->PrevAddr;
		Node* PNextNode = PDeleteNode->NextAddr;

		//������ ��� ���� �հ� �ڳ��� ����
		PPrevNode->NextAddr = PNextNode;
		PNextNode->PrevAddr = PPrevNode;
	}
	else
	{// �����Ϸ��� ��尡 �ǳ� ����� ���
		Node* PPrevNode = PDeleteNode->PrevAddr;

		//������ ��� ���� �ڴ� �������� ó��
		PPrevNode->NextAddr = nullptr;

		//�ǳ� ��� �ּ� ����
		PTailNode = PPrevNode;
	}

	// ��[�����Ҵ� ����]
	delete PDeleteNode;
	PDeleteNode = nullptr;
}// END - void DeleteNode(int InData)


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
void Insert(int InData, int PrevData)
{
	Node* PPrevNode = FindByData(PrevData);

	if (PPrevNode == PTailNode)
	{
		/*
		���� ��尡 �ǳ� ����� ���
		�Ǵ� ������� ������ ���� ��ġ�ϴ� ������尡 ���� ���
		*/

		// ��[�����Ҵ� �߻�]
		Node* PAddNode = new Node();
		PAddNode->Data = InData;
		PAddNode->NextAddr = nullptr;
		PAddNode->PrevAddr = PPrevNode;

		// ������ ���� ��� ���� ����
		PPrevNode->NextAddr = PAddNode;

		//�ǳ� ��� �ּ� ����
		PTailNode = PAddNode;
	}
	else
	{
		Node* PNextNode = PPrevNode->NextAddr;

		// ��[�����Ҵ� �߻�]
		Node* PAddNode = new Node();
		PAddNode->Data = InData;
		PAddNode->NextAddr = PNextNode;
		PAddNode->PrevAddr = PPrevNode;

		// ������ ���� ���� ���� ��� ���� ����
		PPrevNode->NextAddr = PAddNode;
		PNextNode->PrevAddr = PAddNode;
	}
}//END - void Insert(int InData, int PrevData)

// �޸� ����
// ��� ��� �����Ҵ� ����
void ReleaseNodes()
{
	Node* PNode = PTailNode;

	while (PNode != nullptr)
	{// �ǳ� ������ ��ó�� ������ �ݺ�
		Node* PDeleteNode = PNode;
		PNode = PNode->PrevAddr;

		// ��[�����Ҵ� ����]
		delete PDeleteNode;
		PDeleteNode = nullptr;
	}
}//END - void ReleaseNodes()