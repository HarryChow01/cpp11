
#include <set>
#include <iostream>
using namespace std;

void testSet() {
    set<int> myset = {1, 2, 3};

    myset.emplace(4);
    myset.emplace(5);
    auto ret = myset.emplace(4);


    if (!ret.second) std::cout << "4 already exists in myset\n";
    for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12
    auto it = myset.begin();    // "it" points to 1
    ++it;                                         // "it" points now to 2
    myset.erase(it);
    myset.erase(40);   // "40" not exist, won't core

    for (int i=0; i<10; ++i) {
        std::cout << i;
        if (myset.count(i)!=0)
            std::cout << " is an element of myset.\n";
        else
            std::cout << " is not an element of myset.\n";
    }

}


int main() {
    testSet();
    return 0;
}

