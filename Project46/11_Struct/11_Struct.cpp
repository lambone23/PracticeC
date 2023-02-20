#include <iostream>


struct Vector3
{
    float x;
    float y;
    float z;
};

struct Player
{
    int hp;
    int mp;
    int stamina;
};

void SetHp(Player* _this, int hp)
{
    //(*_this).hp = hp;
    _this->hp = hp;
}


class Monster
{
public:
    void SetHp(/*Monster* const this,*/ int _hp)
    {
        if (_hp > 100)
        {
            //(*this).hp = 100;
            this->hp = 100;
        }

        hp = _hp;
    }

private:
    int hp;
    int mp;
};

int main()
{
    //int len;
    //std::cin >> len
    //int arr[len];
    const float PI = 3.141592f;
    const int player1HP = 100;
    int player2HP = 100;
    int player3HP = 100;

    int player1MP = 100;
    int player2MP = 100;
    int player3MP = 100;

    int player1Stamina = 100;
    int player2Stamina = 100;
    int player3Stamina = 100;



    Player p1;
    Player p2;
    Player p3;

    const Player* const _this = &p1;
    //_this = &p2;
    //(*_this).hp = 200;
    //DrawColorPallete();
    SetHp(&p1, 100);
    SetHp(&p2, 100);
    SetHp(&p3, 100);
    //p1.stamina = 100;

    int len = sizeof(p1);

    Monster m1;
    m1.SetHp(987654321);

    Monster m2;
    m2.SetHp(50);
    //m1.hp = 100;
    //m1.mp = 100;




    return 0;
}

