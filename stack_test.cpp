
#include <stack>
#include <iostream>

using namespace std;


int main() {
    stack<int> mystack;
    cout << "mystack empty: " << mystack.empty() << endl;
    mystack.push(12);
    mystack.push(75);
    cout << "mystack size: " << mystack.size() << endl;
    cout << "mystack top: " << mystack.top() << endl;
    mystack.top() -= 10;
    cout << "mystack top: " << mystack.top() << endl;
    mystack.emplace(30);
    while (!mystack.empty()) {
        int top = mystack.top();
        cout << "mystack top: " << top << endl;
        mystack.pop();
    }

    return 0;
}


