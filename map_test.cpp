
#include<utility>   // std::pair
#include <map>
#include <iostream>
#include <memory>

using namespace std;

void testMap() {
    std::map<char,int> mymap2 = {
            {'a', 1},
            {'b', 2},
    };
    std::map<char,int> mymap;
    using mapIt = std::map<char,int>::iterator;
    mapIt itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;


    cout << "x => " << mymap['x'] << endl;  // x not exists
    mymap['x'] = 120;
    cout << "x => " << mymap['x'] << endl;
    mymap.insert(pair<char,int>('x', 140));  // fail, if key exists, insert will fail.
    mymap.insert(pair<char,int>('y', 140));  // ok.
    mymap.emplace('y', 180);  // fail, if key exists, insert will fail.
    mymap.emplace('z', 180);  // ok.

    auto it = mymap.find('b');
    mymap.erase(it);    // erasing by iterator, ok
    //it = mymap.end();
    //mymap.erase(it);    // erasing by iterator, it point error, will core
    mymap.erase('c');   // erasing by key, ok
    mymap.erase('f');   // erasing by key, 'f' not exists, won't core;

    pair<char,int> mypair = std::make_pair('z', 180);   // ok

    itlow = mymap.lower_bound ('d');  // itlow points to b
    itup = mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (auto& item : mymap)
        std::cout << item.first << " => " << item.second << '\n';
}



using namespace std;

struct XX {
    std::unique_ptr<int> pInt;
    int age = 0;
    XX(int pp = 0) {
        age = pp;
        std::cout << "default construct" << std::endl;
    }
    XX(const XX& xx) {
        std::cout << "default copy" << std::endl;
    }
    XX& operator=(const XX& xx) {
        std::cout << "default assign" << std::endl;
        return *this;
    }
    ~XX() = default;
};

void map_test() {
    std::map<string, XX> testMap;
    //XX xx;
    //testMap["aa"] = xx;   // 2次构造，1次拷贝

    //testMap["bb"] = XX(); // 2次构造，1次拷贝

    testMap.emplace("cc", 15);  // 1次调用构造函数

}

int main() {
    //testMap();
    map_test();

    return 0;
}


