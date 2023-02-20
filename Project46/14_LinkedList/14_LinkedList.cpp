#include <iostream>
//#include "yaList.h"
#include "hLinkedList.h"


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(187);
    Node n1;
    Node n2;
    Node n3;

    /*
    n1.data = 3;
    n1.next = &n2;

    n2.data = 4;
    n2.next = &n3;

    n3.data = 5;
    n3.next = nullptr;

    std::cout << n1.data;
    std::cout << n1.next->data;

    AddNode(1);
    AddNode(2);
    AddNode(3);
    AddNode(4);

    DeleteNode(2);

    ReleaseNodes();
    */

    PrintNodes();   //없음

    AddNode(1);
    PrintNodes();   //1

    AddNode(2);
    PrintNodes();   //1 2

    AddNode(3);
    AddNode(4);
    PrintNodes();   //1 2 3 4

    DeleteNode(2);
    PrintNodes();   //1 3 4

    Insert(9, 1);
    PrintNodes();   //1 9 3 4

    Insert(7, 4);
    PrintNodes();   //1 9 3 4 7

    Insert(5, 4);
    PrintNodes();   //1 9 3 4 5 7

    Insert(2, 3);
    PrintNodes();   //1 9 3 2 4 5 7

    Insert(6, 7);
    PrintNodes();   //1 9 3 2 4 5 7 6

    ReleaseNodes();

    return 0;
}

