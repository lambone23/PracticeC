#include <iostream>

// 얕은 복사
// call by value
//void swap(int a, int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}

// 깊은 복사
// call by reference
//void swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print(char* str)
{
    //printf("%s", str);

    std::cout << str;
}

int yaStrlen(char* str)
{
    //std::cout << *(str + 1);

    for (int i = 0; i < 256; i++)
    {

        //char ch = *(str + i);
        // 가독성이 너무나 떨어지는 문법
        // 포인터 변수는 배열처럼 사용이 가능하다
        char ch = str[i];

        if (ch == '\0')
        {
            return i;
        }
    }

    return 0;
}

int yaIntlen(int* str)
{
    //std::cout << *(str + 1);

    for (int i = 0; i < 256; i++)
    {
        int ch = *(str + i);
        if (ch == '\0')
        {
            return i;
        }
    }

    return 0;
}

void test(int(*pArr)[2])
{

}

void testA(char str[10])
{

}

void testA(char str[10][10])
{

}

int main()
{
    int d = 9;
    int e = 10;

    swap(d, e);

    // 정수 저장하려면 어떤 자료형 타입 -> int
    // 글자는 저장하려면 -> char. wchar_t
    // 포인터 변수 : 주소를 저장할수 있는 자료형의 타입
    // 포인터 변수의 크기는 운영체제의 데이터처리 크기에따라서
    // 정해진다 64비트 환경에선 8바이트 정수
    // 32비트 환경에서는 4바이트
    // 4바이트 최대값 대략 42억


    // 단순하게 주소만 저장할용도로 사용한다면 
    // void* 또는 정수를 저장할수 있는 데이터타입을 
    // 사용해도 무관하다.
    //void* p = &d;

    int* p;
    p = &d;
    p = &e;
    //unsigned int ref = (int)&d;

    //하지만 포인터변수에는 특별한 기능이 있다.
    //그것을 역참조라고 한다.
    //가르키는 기능 가리키다

    //std::cout << p ;
    //std::cout << *p;

    char strA[256] = "Hello";
    //print(&strA[0]);
    //print(strA);

    int strb[256] = { 1,2,3,4,5 };

    int len = yaStrlen(strA);
    int len2 = yaIntlen(strb);

    // 포인터의 제일큰 단점
    // 다루기 어렵다
    // 대체제가 있다. 레퍼런스 &

    int num = 10;
    int& ref = num;
    ref = 200;


    int arr[3][2] = { 1,2,
    3,4,
    5,6, };

    int(*pArr)[2] = arr;

    std::cout << (*(pArr)) << std::endl; //[0][0]
    std::cout << (*(pArr)+1) << std::endl; //[0][1]

    std::cout << (*(pArr + 1)) << std::endl; //[1][0]
    std::cout << (*(pArr + 1) + 1) << std::endl; //[1][1]

    std::cout << (*(pArr + 2)) << std::endl; //[2][0]
    std::cout << (*(pArr + 2) + 1) << std::endl; //[2][1]

    pArr[0][0] = 100;

    int(*i)[2] = arr;
    for (int(&i)[2] : arr)
    {

        int a = 0;
    }

    for (int* i : arr)
    {

        int a = 0;
    }

    for (size_t y = 0; y < 3; y++)
    {
        for (size_t x = 0; x < 2; x++)
        {
            i[y][x];
        }
    }

    //int* i[3]와 int& i[3]은 어떻게 다를까요

    return 0;
}

