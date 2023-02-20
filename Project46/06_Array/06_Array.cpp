// 06_Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    //// 배열

    //// 변수를 한번에 여러개 생성

    //int a = 0;
    ////int arr[5] = {1,2,7,4,5};
    int arr[5] = { 1,2,3,4,5 };

    int arr2D[3][5] =
    {
        { 1,2,3,4,5},
        { 1,2,3,4,5},
        { 1,2,3,4,5},
    };

    int arr2D[3][5] =
    {
        { 1,2,3,4,5},
        { 1,2,3,4,5},
        { 1,2,3,4,5},
    };


    //// 배열의 위치는 인덱스로 구분한다.
    ////arr[0] = 999;
    ////arr[4] = 999;
    ////arr[5] = 999;

    //// 배열은 for문과 만났을때 시너지효과가 엄청나다.

    //int i = 0;
    //for ( i = 0; i < 5; i++ )
    //{
    //    arr[i] = i;
    //}

    //std::cin >> arr[0];

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        int value = arr[i];
        value = 999999123;
    }


    for (int value : arr)
    {
        value = 3;
        std::cout << value;
    }

    //int Array[5] = {};

    //int i = 0;
    //for (i = 0; i < 5; i++)
    //{
    //    std::cin >> Array[i];
    //}

    //for (i = 0; i < 5; i++)
    //{
    //    //Array[i] += 1;
    //    Array[0]++;
    //}

    //for (i = 0; i < 5; i++)
    //{
    //    std::cout << Array[i];
    //}


    char str[5] = { 'A', 'B', 'C', 'D', 'E' };
    //std::cout << str;
    //std::cout << str[0];
    //std::cout << str[1];
    //std::cout << str[2];
    //std::cout << str[3];
    //std::cout << str[4];


    //  문자열 , 문자 배열, 문장
    char str2[6] = "ABCDE";
    std::cout << str2;


    return 0;
}

