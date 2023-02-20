#include <iostream>

#include <vector>
#include "yaVector.h"

// FIFO
#include <queue>

// FILO
#include <stack>

// list
#include <list>

#include <map>
#include <unordered_map>

std::map<int, std::wstring> map;

#include <set>
#include <unordered_set>

#include <algorithm>

//std::set<std::wstring> set;
//Standard Template Libarary

struct Monster
{
    int hp;
    int level;
};

bool compareLevel(Monster& a, Monster& b)
{
    return a.level > b.level;
}

bool compareHp(Monster& a, Monster& b)
{
    return a.hp > b.hp;
}

int main()
{
    ya::vector<int> yaVector;
    yaVector.resize(10);
    yaVector.push_bakc(1);
    yaVector.push_bakc(2);

    yaVector[0] = 200;

    ya::vector<int> yaVector2;
    yaVector2 = yaVector;

    std::vector<int> stdVector; //= { 1,2,3,4,5};
    stdVector.resize(10);
    stdVector.push_back(1);
    stdVector.pop_back();

    stdVector[0] = 200;



    std::vector<int> stdVector2;
    stdVector2 = stdVector;

    stdVector2.clear();

    //std::vector<Monster> vector; //= { 1,2,3,4,5};
    //vector.reserve(10);
    /////vector.resize(15);

    //vector.push_back(Monster{ 22 ,1 });
    //vector.push_back(Monster{ 102,99 });
    //vector.push_back(Monster{ 32,1 });
    //vector.push_back(Monster{ 62,3 });
    //vector.push_back(Monster{ 12,5 });
    //vector.push_back(Monster{ 2,2 });

    //std::sort(vector.begin(), vector.end(), compareLevel);
    //std::sort(vector.begin(), vector.end(), compareHp);

    //for (size_t i = 0; i < vector.size(); i++)
    //{
    //    std::cout << vector[i];
    //}

    return 0;
}

