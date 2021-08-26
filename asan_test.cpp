
#include <iostream>
using namespace std;

void testAsan1() {
    int* p = new int[5];
}

int main() {
    testAsan1();
    std::cout << "end testAsan1" << std::endl;
    return 0;
}

