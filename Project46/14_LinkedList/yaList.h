#pragma once

int g = 100;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void AddNode(int data)
{
	g = 200;
	if (head == nullptr)
	{
		head = new Node();
		head->data = data;
		head->next = nullptr;
		head->prev = nullptr;

		tail = head;
	}
	else
	{
		Node* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}

		p->next = new Node();
		p->next->prev = p;
		p->next->data = data;
		p->next->next = nullptr;

		tail = p->next;
	}
}

// 노드 찾아서 주소값 반환
Node* Find(int data)
{
	Node* p = head;
	while (p->next != nullptr)
	{
		if (data == p->data)
		{
			return p;
		}
		p = p->next;
	}

	return nullptr;
}

// 삭제

void DeleteNode(int data)
{
	Node* findNode = Find(data);
	g = 200;
	Node* prev = findNode->prev;
	Node* next = findNode->next;

	prev->next = next;
	next->prev = prev;

	delete findNode;
	findNode = nullptr;
}



// 삽입
void Insert(int data, int target)
{
	Node* find = Find(target);
	Node* nextNode = find->next;

	Node* newNode = new Node();
	newNode->data = data;

	find->next = newNode;
	newNode->prev = find;

	newNode->next = nextNode;
	nextNode->prev = nextNode;
}


// 메모리 해제

void ReleaseNodes()
{
	Node* p = tail;
	while (p != nullptr)
	{
		Node* delNode = p;
		p = p->prev;
		delete delNode;
		delNode = nullptr;
	}


}