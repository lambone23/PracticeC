// 25_TrueOfOOP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 객체지향 프로그래밍 이란?
// 현실세계이 있는 객체를 본따서 프로그래밍 한다.

// 하지만 현실세계를 모방한 프로그래밍이라고 알려져 있지만
// 현실세계를 일반화하는 것은 아니다!
// 현실세계와는 다르게 프로그래밍 가능하다라는 점을
// 꼭 기억해야한다.

class cola
{
public:
    int brix = 10;
    int amount = 100;

    void Decrease()
    {
        amount -= 10;
    }
};

class People
{
public:
    void Drink(cola* col)
    {
        col->amount -= 10;
    }


    bool Drinking()
    {
        return true;
    }
};

//class Message
//{
//
//};

// 객체지향 프로그래밍 방법
// 첫번째로 상태가아닌 행동이 무조건 우선시 되어야한다.
// 상태(변수)는 거들뿐
// 멤버변수보다는 멤버함수를 고민한다.
// 행동이 상태를 결정한다.
class Packmen
{
public:
    int x;
    int y;

public:
    void Move()
    {

    }
};

// 클래스 이름 ( 하는 역할 (책임)) 
// 하는 역할 (함수)에 기반하여 나눠야한다.

// 모든 객체는 자율절인 존재가 되어야 한다.


// 기능 하고 구조를 잘 구분해서 고민해서 사용해야한다.
// 추후에 재사용성이 용이한가 정도는 고민해야한다.

int main()
{

    cola p1;
    cola p2;

    People dongsuck;


    // 1
    dongsuck.Drink(&p1);


    // 2
    if (dongsuck.Drinking())
    {
        p1.Decrease();
    }

    return 0;
}

