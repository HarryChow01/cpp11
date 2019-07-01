
#include <deque>
#include <iostream>
using namespace std;

void testDeque1() {
    std::deque<int> mydeque = {10,20,30};

    auto it = mydeque.emplace ( mydeque.begin()+1, 100 );
    mydeque.emplace ( it, 200 );
    mydeque.emplace ( mydeque.end(), 300 );

    std::cout << "mydeque contains:";
    for (auto& x: mydeque)
        std::cout << ' ' << x;
    std::cout << '\n';
}

void testDeque2() {
    std::deque<int> mydeque;
    int sum (0);
    mydeque.push_back (10);
    mydeque.push_back (20);
    mydeque.push_back (30);

    while (!mydeque.empty()) {
        sum+=mydeque.back();
        mydeque.pop_back();
    }

    std::cout << "The elements of mydeque add up to " << sum << '\n';
}

void testDeque3() {
    std::deque<int> mydeque (2,100);     // two ints with a value of 100
    mydeque.push_front (200);
    mydeque.push_front (300);

    std::cout << "mydeque contains:";
    for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main() {
    testDeque1();
    testDeque2();
    testDeque3();

    return 0;
}


