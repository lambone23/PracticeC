// 21_Inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int gHP = 100;


// 포함관계

struct Pos
{
    int x;
    int y;

    int DoJumToSai()
    {

    }

    int distance()
    {

    }
};


struct Stat
{
    int level;
    int hp;
    int stamina;
};

class GameObject
{
private:
    Stat stat;

    //protected:
    //    bool death;

public:
    virtual void Shouting()
    {

    }

    void Damaged()
    {
        stat.hp -= 10;
    }

    GameObject()
    {

    }

    ~GameObject()
    {

    }
};

struct Player : public GameObject
{
private:
    int mp = 0;

public:
    virtual void Shouting() override
    {
        std::cout << "나는 플레이어다.";
    }
};

struct Monster : public GameObject
{
public:
    virtual void Shouting() override
    {
        std::cout << "나는 몬스터어다.";
    }
};

class NPC : public GameObject
{
public:
    NPC()
    {

    }

    ~NPC()
    {

    }

    virtual void Shouting() override
    {
        std::cout << "나는 NPC어다.";
    }
};


int main()
{
    //Player pl;
    //pl.Damaged();
    //pl
    //pl.Damaged

    //int* p;
    //char* cp = p;

    NPC* npc = new NPC();
    Monster* mon = new Monster();
    Player* player = new Player();

    player->Shouting();

    GameObject* allObject[3] = { npc, mon, player };

    npc->Damaged();
    mon->Damaged();
    player->Damaged();

    for (size_t i = 0; i < 3; i++)
    {
        //allObject[i]->Damaged();

        allObject[i]->Shouting();
    }
    int len = sizeof(GameObject);

    return 0;
}

