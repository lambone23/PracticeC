// 13_HashTable(DirectAddressTable).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
typedef unsigned int TEST;

int main()
{
    int bucket[512] = {};
    //'A'
    char str[256] = "ABCDEFFGHYYJJGFDCVZ";

    //for (size_t i = 'A'; i < 'Z'; i++)
    //{
    //    int cnt = 0;
    //    for (size_t j = 0; j < 256; j++)
    //    {
    //        if (str[j] == i)
    //        {
    //            cnt++;
    //        }
    //    }
    //}

    for (size_t i = 0; i < 256; i++)
    {
        char ch = str[i];
        bucket[ch] += 1;
        //bucket[ch]++;
    }

    for (TEST i = 0; i < 512; i++)
    {
        if (bucket[i] != 0)
        {
            for (TEST j = 0; j < bucket[i]; j++)
            {
                std::cout << (char)i;
            }
        }
    }

    return 0;
}

