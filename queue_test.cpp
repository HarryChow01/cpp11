
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void queueTest() {
    std::queue<int> myqueue;
    cout << "myqueue empty: " << myqueue.empty() << endl;
    myqueue.push(12);
    myqueue.push(75);
    cout << "myqueue size: " << myqueue.size() << endl;
    cout << "myqueue front: " << myqueue.front() << endl;
    myqueue.back() -= myqueue.front();
    cout << "myqueue back: " << myqueue.back() << endl;
    myqueue.emplace(30);
    while (!myqueue.empty()) {
        int first = myqueue.front();
        cout << "myqueue first: " << first << endl;
        myqueue.pop();
    }
}

int main() {

    queueTest();
    return 0;
}


