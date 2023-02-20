#include <iostream>

//void* NEW(int len);
//void* __CRTDECL operator new[](size_t _Size);


//class Player
//{
//    int hp;
//    int mp;
//    int stamina;
//};

struct Player
{
    int hp;
    int mp;
    int stamina;
};

int main()
{
    int len = 100;
    /*   std::cin >> len;*/

    int* p = new int;
    *p = 3;
    delete p;
    free(p);

    while (true)
    {
        char* str = new char[len];
        //char* str = (char*)malloc(100);

        //int* p = nullptr;
        //std::cout << (*p);
        str[0] = 'A';
        str[1] = 'A';
        str[2] = 'A';

        delete[] str;
        //free(str);

        str[0] = 'A';

        // Java
        // C++
        // C#
        // TOOL

        // IMGUI OPENSOURCE C++
    }

    Player* player = new Player;
    //Player* player = new Player[256];
    //(*player).hp
    player->hp = 200;

    delete player;


    return 0;
}



