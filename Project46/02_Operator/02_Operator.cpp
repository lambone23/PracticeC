#include <iostream>

int main()
{
    //+ - / * %

    int sum = 0;

    int a = 12;
    int b = 13;
    int c = 16;


    sum = a;
    //sum = sum + b;
    sum += b;
    // -= 
    // *=
    // /=
    sum = sum + c;

    sum = sum + 1;
    sum += 1;

    // 증감 연산자
    int d = sum++;
    d = sum--;

    d = ++sum;
    d = --sum;

    // 비트 연산자
    int t = 9;
    int g = 13;

    int z = t ^ g;
    // & AND
    // | OR
    // ^ XOR
    // ~ NOT
    // >> << 시프트
    //4,294,967,295 - 1
    unsigned int p = 2;
    unsigned int y = p >> 1;

    // 논리 연산자

    int a = 5;



    if (a > 0)
    {
        if (a % 2 == 1)
        {

        }
    }

    if (a > 0 && (a % 2 == 1))
    {

    }
    if (a > 0 || (a % 2 == 1))
    {

    }

    // 부등식
    // 10 <= a <= 20
    if (10 <= a && a <= 20)
    {

    }


    return 0;
}

