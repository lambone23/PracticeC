// 07_Variable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "test.h"


// 전역변수
int gNum = 100;



int main()
{
    // 지역 위치  {} 안에 들어가있는 변수 
    // 지역변수
    //gNum;

    //// 지역변수
    //int g = 0;
    //if (true)
    //{
    //    g = 10; gNum;
    //}

    //int i;
    //for (i = 0; i < 5; i++)
    //{
    //    g = 10;
    //    gNum = 3213;
    //}

    //{
    //    g = 10;
    //    gNum - 299;
    //}

    // 정수
    int num = 0;
    char ch = 0;

    ch = 'A';
    //□□□□□
    wchar_t wCh = L'아';

    //형변환 
    std::cout << (int)(ch);
    std::cout << (char)(65 + 32);

    return 0;
}


