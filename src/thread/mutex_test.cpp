#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block (int n, char ch) {
    // critical section (exclusive access to std::cout signaled by locking mtx):
    mtx.lock();
    for (int i=0; i<n; ++i) { std::cout << ch; }
    std::cout << '\n';
    mtx.unlock();
}

void print_block2 (int n, char ch) {
    std::lock_guard<std::mutex> lock(mtx);
    for (int i=0; i<n; ++i) { std::cout << ch; }
    std::cout << '\n';
}

int main () {
    std::thread th1 (print_block,50,'*');
    std::thread th2 (print_block,50,'$');

    th1.join();
    th2.join();

    std::thread th3(print_block2, 50, 'x');
    std::thread th4(print_block2, 50, 'y');

    th3.join();
    th4.join();

    return 0;
}





