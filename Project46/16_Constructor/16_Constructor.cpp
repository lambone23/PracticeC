#include <iostream>
#include <Windows.h>



class GameObject
{
public:
    GameObject()
        : mX(0)
        , mY(0)
        , mName(nullptr)
    {

    }

    //GameObject()
    //{
    //    mX = 0;
    //    mY = 0;
    //}

    GameObject(int x, int y)
        : mX(x)
        , mY(y)
        , mName(nullptr)
    {

    }

    GameObject(const char* name)
        : mX(0)
        , mY(0)
        , mName(nullptr)
    {
        mName = new char[256];
        memset(mName, 0, 256);
        memcpy(mName, name, 256);
        //ZeroMemory();
    }

    //소멸자
    ~GameObject()
    {
        delete mName;
        mName = nullptr;

        //mName = new char[256];
    }

    //void Release()
    //{
    //    delete mName;
    //}

private:
    char* mName;
    int mX;
    int mY;
};

int main()
{
    GameObject obj2("LJJ");
    //obj2.Initialize();

    //GameObject* obj = new GameObject();
    //GameObject obj(5, 3);

    // 대입, 초기화
    int a = 0;

    int b;
    b = 0;

    //delete obj;
    //obj2.Release();

    return 0;
}


