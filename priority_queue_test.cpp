
#include <queue>
#include <iostream>
using namespace std;

template<class T>
ostream& operator<<(ostream& out, priority_queue<T>& pqueue) {
    for (auto& item : pqueue) {
        out << " " << item;
    }
    return out;
}

void testPriorityQueue1() {
    std::priority_queue<int> mypq;

    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);

    std::cout << "Popping out elements...";
    while (!mypq.empty())
    {
        std::cout << ' ' << mypq.top();
        mypq.pop();
    }
    std::cout << '\n';
}

void testPriorityQueue2() {
    std::priority_queue<int> mypq;

    mypq.emplace(30);
    mypq.emplace(100);
    mypq.emplace(25);
    mypq.emplace(40);

    std::cout << "Popping out elements...";
    while (!mypq.empty()) {
        std::cout << ' ' << mypq.top();
        mypq.pop();
    }
    std::cout << '\n';
}

int main() {
    testPriorityQueue2();

    return 0;
}


