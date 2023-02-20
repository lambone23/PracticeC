#include <iostream>
using namespace std;

struct Node
{
    int Data = 0;
    Node* Next = nullptr;
};

int main()
{
    Node* head = new Node;

    head->Next = new Node;
    head->Next->Data = 3;

    head->Next->Next = new Node;
    head->Next->Next->Data = 5;

    head->Next->Next->Next = new Node;
    head->Next->Next->Next->Data = 4;

    head->Next->Next->Next->Next = new Node;
    head->Next->Next->Next->Next->Data = 2;
    head->Next->Next->Next->Next->Next = nullptr;

    Node* Head = head;

    while (true)
    {
        if (Head->Data != '\0')
        {
            cout << Head->Data << " ";
        }

        if (Head->Next == nullptr)
        {
            break;
        }

        Head = Head->Next;
    }

    delete head->Next->Next->Next->Next;
    delete head->Next->Next->Next;
    delete head->Next->Next;
    delete head->Next;
    delete head;

    return 0;
}
