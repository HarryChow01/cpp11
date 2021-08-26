#include <atomic>
#include <thread>
#include <iostream>

using namespace std;

std::atomic<uint64_t*> p1;
std::atomic<uint64_t*> p2;


int main() {
    std::atomic<uint64_t*> p1(new uint64_t(1UL));
    std::atomic<uint64_t*> p2(new uint64_t(2UL));
    auto p1x = p1.load();
    auto p2x = p2.load();
    std::cout << "p1x: " << static_cast<void*>(p1x) << ", p2x: " << static_cast<void*>(p2x) << std::endl;
    std::cout << "*p1x: " << *p1x << ", *p2x: " << *p2x << std::endl;

    p1.exchange(p2);
    p1x = p1.load();
    p2x = p2.load();
    std::cout << "p1x: " << static_cast<void*>(p1x) << ", p2x: " << static_cast<void*>(p2x) << std::endl;
    std::cout << "*p1x: " << *p1x << ", *p2x: " << *p2x << std::endl;

    return 0;
}

