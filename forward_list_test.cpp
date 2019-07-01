
#include <forward_list>
#include <iostream>
using namespace std;

// 为什么没有后端插入：https://stackoverflow.com/questions/8742462/stdforward-list-and-stdforward-listpush-back

template<class T>
ostream& operator<<(ostream& out, forward_list<T>& flist) {
    for(auto& item : flist) {
        out << " " << item;
    }
    return out;
}

void testForwardList1() {
    // constructors used in the same order as described above:

    std::forward_list<int> first;                      // default: empty
    std::forward_list<int> second(3, 77);              // fill: 3 seventy-sevens
    std::forward_list<int> third(second.begin(), second.end()); // range initialization
    std::forward_list<int> fourth(third);            // copy constructor
    std::forward_list<int> fifth(std::move(fourth));  // move ctor. (fourth wasted)
    std::forward_list<int> sixth = {3, 52, 25, 90};    // initializer_list constructor

    std::cout << "first:" << first;
    std::cout << "second:" << second;
    std::cout << "third:" << third;
    std::cout << "fourth:" << fourth;
    std::cout << "fifth:" << fifth;
    std::cout << "sixth:" << sixth;

}

// insert a integer list
void testForwardList2() {

    std::forward_list<int> myflist;
    //cout << "front: " << myflist.front(); // if myflist is empty, will core

    using flistIt = forward_list<int>::iterator;
    auto it = myflist.before_begin();
    for (int i = 0; i < 5; ++i) {
        it = myflist.insert_after(it, i);
    }
    myflist.pop_front();

    auto lastIt = myflist.before_begin();
    cout << "myflist:";
    for (auto it2 = myflist.begin(); it2 != myflist.end(); ++it2) {
        cout << " " << *it2;
        ++lastIt;
    }
    cout << endl;

    cout << "myflist:";
    for (auto it3 = myflist.cbegin(); it3 != myflist.cend(); ++it3) {
        cout << " " << *it3;
    }
    cout << endl;

}

void testForwardList3() {
    std::forward_list<int> mylist = {10, 20, 30, 40};

    std::cout << "Popping out mylist:";
    while (!mylist.empty()) {
        std::cout << ' ' << mylist.front();
        mylist.pop_front();
    }
    cout << endl;
    cout << "mylist empty: " << mylist.empty() << endl;
}

void testForwardList4() {
    std::forward_list<int> myflist = {10, 20, 30, 40, 50};
    auto it = myflist.before_begin();

    myflist.erase_after(it);
    cout << "myflist:" << myflist << endl;
    myflist.erase_after(myflist.begin());
    cout << "myflist:" << myflist << endl;

    myflist = {10, 20, 30, 40, 50};
    //myflist.erase_after(myflist.end()); // will core
    //it = myflist.end();
    // myflist.erase_after(it); // will core
    cout << "myflist:" << myflist << endl;

    it = myflist.before_begin();
    size_t length = 0;
    for (auto& item : myflist) {
        ++it;
        ++length;
    }
    cout << "last value: " << *it << endl;
    // myflist.erase_after(it); // can't delete after last elem;
    // cout << "myflist:" << myflist << endl;
    it = myflist.before_begin();
    std::advance(it, length - 1);
    cout << "last 2nd value: " << *it << endl;
    myflist.erase_after(it);
    cout << "myflist:" << myflist << endl;

}

void testForwardList5() {
    std::forward_list<int> myflist = { 1,100,2,3,10,1,11,12 };

    myflist.remove(1); // 删除值等于1的元素
    myflist.remove_if([](int n){ return n > 10; }); // 删除所有值大于10的元素

    cout << "myflist:" << myflist << endl;
}


int main() {
    //testForwardList1();
    //testForwardList2();
    //testForwardList3();
    //testForwardList4();
    testForwardList5();

    return 0;
}


