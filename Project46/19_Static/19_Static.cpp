#include <iostream>
#include "Test.h"




int main()
{
    gNum = 200;

    Test test;

    Test test2;

    //Test::number = 200;
    // 클래스 내부에서 하나만 생성되는 객체 또는 변수
    Test::PrintNumber();

    return 0;
}
