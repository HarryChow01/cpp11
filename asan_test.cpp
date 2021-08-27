
#include <csignal>
#include <iostream>
#include <sanitizer/lsan_interface.h>
#include <chrono>
#include <thread>

using namespace std;

void testAsan1() {
    int* p = new int[5];
    p = 0;
}

void signalHandler(int signalNo) {
    std::cout << "Interrupt signal (" << signalNo << ") received." << std::endl;

    //__lsan_do_recoverable_leak_check();
    __lsan_do_leak_check();
    this_thread::sleep_for(chrono::seconds(5));

    exit(0);
}

int main() {
    signal(SIGINT, signalHandler);
    testAsan1();
    //__lsan_do_recoverable_leak_check();

    //int* p = new int[5];
    //p = 0;
    std::cout << "wait ctrl + c" << std::endl;
    while (true);
    std::cout << "end testAsan1" << std::endl;
    return 0;
}

