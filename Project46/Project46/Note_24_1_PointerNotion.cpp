#include <iostream>
using namespace std;

int main()
{
    int c = 3;

    int* b = &c;

    int** a = &b;
    int** t = &b;

    int f = 6;

    int* k = &f;

    int** p = &k;



    cout << "a 蔼   : " << a << endl;
    cout << "a 林家 : " << &a << endl;
    cout << "b 蔼   : " << b << endl;
    cout << "b 林家 : " << &b << endl;
    cout << "c 蔼   : " << c << endl;
    cout << "c 林家 : " << &c << endl;
    cout << "t 蔼   : " << t << endl;
    cout << "t 林家 : " << &t << endl;
    cout << "----------------" << endl;
    cout << "f 蔼   : " << f << endl;
    cout << "f 林家 : " << &f << endl;
    cout << "k 蔼   : " << k << endl;
    cout << "k 林家 : " << &k << endl;
    cout << "p 蔼   : " << p << endl;
    cout << "p 林家 : " << &p << endl;
    cout << "=================" << endl;
    cout << "a狼 蔼 : " << a << endl;
    cout << "k狼 蔼 : " << k << endl;
    cout << "t狼 蔼 : " << t << endl;
    cout << "c狼 林家 : " << &c << endl;
    cout << "*a : " << (*a) << endl;
    cout << "**p : " << (**p) << endl;
    cout << "&k : " << (&k) << endl;
    cout << "*p : " << (*p) << endl;



    return 0;
}
