#include <iostream>
#include <stdio.h>
#include <stdarg.h>

// 반환값  이름 (전달인자)
int d = 9;
void HelloWorld05();

//int Add(int _a, int _b)
//{
//    HelloWorld05();
//    return _a + _b;
//    _a = 2;
//}

//float Add(float _a, float _b)
//{
//    HelloWorld05();
//    return _a + _b;
//}
//
//char Add(char _a, char _b)
//{
//    HelloWorld05();
//    return _a + _b;
//}

template <typename T>
T Add(T _a, T _b)
{
    return _a + _b;
}

void changeNumber()
{
    d = 10;
}

typedef int MYINT;

void print(int length, ...)
{
    va_list VA_LIST;
    __crt_va_start(VA_LIST, length);


    for (size_t i = 0; i < length; i++)
    {
        int output = va_arg(VA_LIST, int);
        std::cout << output;
    }

    va_end(VA_LIST);
}


template <typename... T>
void foo(T... args)
{

}


// caller
int main()
{
    foo(1, 'A', 3.0f);

    print(5, 2, 3, 4, 5, 6);

    // calle
    HelloWorld05();


    int f = 9;
    changeNumber();


    // 함수 오버로딩
    //int result = Add(d, f);
    //float fResult = Add(3.2f, 3.3f);

    int result = Add<int>(d, f);
    float fResult = Add<float>(3.2f, 3.3f);
    //char fResult = Add<char>(3.2f, 3.3f);

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    printf("%d %d %d%d %d %d%d %d %d", a, b, c, a, b, c, a, b, c);

    return 0;
}

void HelloWorld05()
{
    std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
}

// 전역변수를 마음껏 쓰면 안될까?
