/*

입력 예제
ABCDEF

출력 결과
ABDECF

*/



#include <iostream>
using namespace std;

class Node
{
public:
	Node()
		: Data(nullptr)
		, left(nullptr)
		, right(nullptr)
	{
		Data = new char;
	}

	void SetData(char InData)
	{
		*Data = InData;
	}

	char GetData()
	{
		return *Data;
	}

	~Node()
	{
		delete Data;
		Data = nullptr;

		//delete left;
		//left = nullptr;

		//delete right;
		//right = nullptr;
	}

	Node* left = nullptr;
	Node* right = nullptr;

private:
	char* Data;
};

void FnRecursive(int Level, Node* PNode)
{
	//cout << "Level : "<< Level << ", 값 :" << PNode->GetData() << endl;
	cout << PNode->GetData();

	if ((PNode->left == nullptr) && (PNode->right == nullptr))
	{
		return;
	}

	if (PNode->left != nullptr)
	{
		Node* TmpPNode = PNode;
		PNode = PNode->left;
		FnRecursive(Level + 1, PNode);
		PNode = TmpPNode;
	}

	if (PNode->right != nullptr)
	{
		Node* TmpPNode = PNode;
		PNode = PNode->right;
		FnRecursive(Level + 1, PNode);
		PNode = TmpPNode;
	}
}

int main()
{
	char Str[7] = "";

	cin >> Str;

	Node* head = new Node();
	head->SetData(Str[0]);
	head->left = new Node;
	head->right = new Node;

	head->left->SetData(Str[1]);
	head->right->SetData(Str[2]);

	head->left->left = new Node();
	head->left->right = new Node();

	head->left->left->SetData(Str[3]);
	head->left->right->SetData(Str[4]);

	head->right->left = new Node();

	head->right->left->SetData(Str[5]);

	FnRecursive(0, head);

	delete head->right->left;

	delete head->left->right;
	delete head->left->left;

	delete head->right;
	delete head->left;

	delete head;

	return 0;
}