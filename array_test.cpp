
#include <array>
#include <iostream>
using namespace std;


void testArray() {
    //size_t num = 4;
    //array<int, num> myarray;  // error, num is variable
    //const size_t kSize2 = num;
    //array<int, kSize2> myarray;  // error, num is variable

    const size_t kSize = 5;
    array<int, kSize> myarray = {0};  // ok
    array<array<int, kSize>, kSize> my2darray = {{0}} ;  // 2D array;
    std::cout << "size of myints: " << myarray.size() << std::endl;
    std::cout << "sizeof(myints): " << sizeof(myarray) << std::endl;

    cout << "column num: " << my2darray[1].size() << endl;

}

int main() {
    testArray();

    return 0;
}


