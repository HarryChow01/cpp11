
#include <time.h>
#include <iostream>


using namespace std;

int main() {
    std::cout << sizeof(time_t) << std::endl;
    std::cout << difftime(2, 1) << std::endl;

    return 0;
}