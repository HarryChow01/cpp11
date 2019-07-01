
#include <list>
#include <iostream>

void testList1() {
    std::list<int> list1(3, 8);
    for(const auto& elem : list1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::list<int> list2;
    for (const auto& elem: list1) {
        list2.emplace_back(elem);
    }

    for (const auto& elem: list2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void testList2() {
    std::list< std::pair<int,char> > mylist;

    mylist.emplace_back(10,'a');
    mylist.emplace_back(20,'b');
    mylist.emplace_back(30,'c');

    std::cout << "mylist contains:";
    for (auto& x: mylist)
        std::cout << " (" << x.first << "," << x.second << ")";

    std::cout << std::endl;
}

void testList3() {
    std::list<int> mylist = {10, 20, 30};
    for (int i = 1; i < 5; ++i) {
        mylist.emplace_front(i);
    }
    for (const auto& elem : mylist) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    //testList1();
    //testList2();
    testList3();

    return 0;
}

