#include <iostream>
#include <climits>
using namespace std;

void climits_test()
{
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "UINT_MAX: " << UINT_MAX << endl;

    cout << "LONG_MAX: " << LONG_MAX << endl;
    cout << "LONG_MIN: " << LONG_MIN << endl;
    cout << "ULONG_MAX: " << ULONG_MAX << endl;
}

/*
 * 已知非等概率函数f()返回0和1概率不一样
 * 构造函数返回0和1的概率是 50% - 50%
 */

int f() {
    return 0;
    // or reurn 1;
}

int g() {
    while(true) {
        int a = f();
        int b = f();

        if ((a == 0) && (b == 1)) {
            return 0;
        }
        if ((a == 1) && (b == 0)) {
            return 1;
        }
    }
}

int main()
{
    climits_test();
    return 0;
}
