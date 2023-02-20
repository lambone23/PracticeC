// 23_FIleIO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";


    int a = 0;
    //int* p = new int();


    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //"D:\\46th\\46th\\save.txt"

    FILE* file = nullptr;
    fopen_s(&file, "D:\\46th\\46th\\save.Hello", "w");
    char buffer[128] = { 0, };

    //fread(buffer, 1, 128, file); //전체 읽기
    fwrite("Hello", 1, 128, file);
    //fwrite("G", 1, 128, file);
    //fwrite("B", 1, 128, file);
    ////printf("%s", buffer);

    //fwrite("A", 1, 128, file);
    //fwrite("G", 1, 128, file);
    //fwrite("B", 1, 128, file);
    //fwrite("R", 1, 128, file);

    ////.txt

    fclose(file);

    return 0;
}

