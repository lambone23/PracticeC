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



    cout << "a ��   : " << a << endl;
    cout << "a �ּ� : " << &a << endl;
    cout << "b ��   : " << b << endl;
    cout << "b �ּ� : " << &b << endl;
    cout << "c ��   : " << c << endl;
    cout << "c �ּ� : " << &c << endl;
    cout << "t ��   : " << t << endl;
    cout << "t �ּ� : " << &t << endl;
    cout << "----------------" << endl;
    cout << "f ��   : " << f << endl;
    cout << "f �ּ� : " << &f << endl;
    cout << "k ��   : " << k << endl;
    cout << "k �ּ� : " << &k << endl;
    cout << "p ��   : " << p << endl;
    cout << "p �ּ� : " << &p << endl;
    cout << "=================" << endl;
    cout << "a�� �� : " << a << endl;
    cout << "k�� �� : " << k << endl;
    cout << "t�� �� : " << t << endl;
    cout << "c�� �ּ� : " << &c << endl;
    cout << "*a : " << (*a) << endl;
    cout << "**p : " << (**p) << endl;
    cout << "&k : " << (&k) << endl;
    cout << "*p : " << (*p) << endl;



    return 0;
}
