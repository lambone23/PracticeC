#include <iostream>


template <typename value, typename ...>
struct Pos
{
    value Add()
    {
        return x + y;
    }

    value x;
    value y;
};

template <>
struct Pos<char>
{
    char Add()
    {
        return x + y;
    }

    char x;
    char y;
};

//struct uPos
//{
//    unsigned int x;
//    unsigned int y;
//};
//
//struct fPos
//{
//    float x;
//    float y;
//};


int main()
{
    Pos<int, int, int, int, int, int, int> pos;
    int ret = pos.Add();

    Pos<float> pos2;
    float ret2 = pos2.Add();

    Pos<char> pos3;
    pos3.Add();

    return 0;
}


