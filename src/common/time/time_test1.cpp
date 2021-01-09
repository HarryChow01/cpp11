
#include <ctime>
#include <chrono>
#include <iostream>


using namespace std;

int main() {
    std::cout << "sizeof(time_t): " << sizeof(time_t) << std::endl;
    std::cout << "difftime(2, 1): " << difftime(2, 1) << std::endl;

    std::chrono::milliseconds msTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
    std::cout << "time in ms: " << msTime.count() << std::endl;

    return 0;
}
