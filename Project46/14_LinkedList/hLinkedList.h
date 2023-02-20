#pragma once

int g = 100;

struct Node
{
	int Data;
	Node* NextAddr;
	Node* PrevAddr;
};

Node* PHeadNode = nullptr; // 맨처음
Node* PTailNode = nullptr; // 맨끝

// 출력
void PrintNodes()
{
	if (PHeadNode == nullptr)
	{
		std::cout << "없음" << std::endl;
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

// 생성
void AddNode(int InData)
{
	g = 200;

	if (PHeadNode == nullptr)
	{// 최초 생성시

		// ■[동적할당 발생] : PHeadNode
		PHeadNode = new Node();
		(*PHeadNode).Data = InData;
		(*PHeadNode).NextAddr = nullptr;
		(*PHeadNode).PrevAddr = nullptr;

		//맨끝 노드 주소 갱신
		PTailNode = PHeadNode;
	}
	else
	{// 기존 헤드 노드 존재시
		Node* PLastNode = PHeadNode;
		
		while ((*PLastNode).NextAddr != nullptr)
		{// 다음 노드가 존재하지 않는 맨끝까지 반복
			PLastNode = (*PLastNode).NextAddr;
		}

		// 다음 노드가 존재하지 않는 경우
		// 맨끝에 새로운 노드 추가

		// ■[동적할당 발생]
		(*PLastNode).NextAddr = new Node(); 
		(*((*PLastNode).NextAddr)).PrevAddr = PLastNode;
		(*((*PLastNode).NextAddr)).Data = InData;
		(*((*PLastNode).NextAddr)).NextAddr = nullptr;
		
		//맨끝 노드 주소 갱신
		PTailNode = (*PLastNode).NextAddr;
	}
}//END - void AddNode(int InData)

// 노드 주소값 반환
// 노드의 데이터 값 기준으로 특정 노드 찾기
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
		{// 다음 노드가 존재하지 않는 맨끝까지 반복

			if (InData == PFindNode->Data)
			{// 노드를 찾은 경우
				return PFindNode;
			}

			// 찾고자 하는 노드가 아닌 경우
			// 다음 노드로 변경
			PFindNode = PFindNode->NextAddr;
		}
	}
}//END - Node* FindByData(int InData)

// 삭제
// 노드의 데이터 값 기준으로 특정 노드 삭제
void DeleteNode(int InData)
{// 연결고리 해제

	//노드 데이터 값 기준으로 삭제할 노드 주소 찾기
	Node* PDeleteNode = FindByData(InData);

	g = 200;

	if (PDeleteNode->NextAddr != nullptr)
	{
		Node* PPrevNode = PDeleteNode->PrevAddr;
		Node* PNextNode = PDeleteNode->NextAddr;

		//삭제할 노드 기준 앞과 뒤끼리 연결
		PPrevNode->NextAddr = PNextNode;
		PNextNode->PrevAddr = PPrevNode;
	}
	else
	{// 삭제하려는 노드가 맨끝 노드인 경우
		Node* PPrevNode = PDeleteNode->PrevAddr;

		//삭제할 노드 기준 뒤는 없음으로 처리
		PPrevNode->NextAddr = nullptr;

		//맨끝 노드 주소 갱신
		PTailNode = PPrevNode;
	}

	// ■[동적할당 해제]
	delete PDeleteNode;
	PDeleteNode = nullptr;
}// END - void DeleteNode(int InData)


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
void Insert(int InData, int PrevData)
{
	Node* PPrevNode = FindByData(PrevData);

	if (PPrevNode == PTailNode)
	{
		/*
		이전 노드가 맨끝 노드인 경우
		또는 이전노드 데이터 값과 일치하는 이전노드가 없는 경우
		*/

		// ■[동적할당 발생]
		Node* PAddNode = new Node();
		PAddNode->Data = InData;
		PAddNode->NextAddr = nullptr;
		PAddNode->PrevAddr = PPrevNode;

		// 기존의 이전 노드 정보 갱신
		PPrevNode->NextAddr = PAddNode;

		//맨끝 노드 주소 갱신
		PTailNode = PAddNode;
	}
	else
	{
		Node* PNextNode = PPrevNode->NextAddr;

		// ■[동적할당 발생]
		Node* PAddNode = new Node();
		PAddNode->Data = InData;
		PAddNode->NextAddr = PNextNode;
		PAddNode->PrevAddr = PPrevNode;

		// 기존의 이전 노드와 이후 노드 정보 갱신
		PPrevNode->NextAddr = PAddNode;
		PNextNode->PrevAddr = PAddNode;
	}
}//END - void Insert(int InData, int PrevData)

// 메모리 해제
// 모든 노드 동적할당 해제
void ReleaseNodes()
{
	Node* PNode = PTailNode;

	while (PNode != nullptr)
	{// 맨끝 노드부터 맨처음 노드까지 반복
		Node* PDeleteNode = PNode;
		PNode = PNode->PrevAddr;

		// ■[동적할당 해제]
		delete PDeleteNode;
		PDeleteNode = nullptr;
	}
}//END - void ReleaseNodes()