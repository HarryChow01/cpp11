#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

template<class T>
ostream& operator<<(ostream& out, std::vector<T>& myVector) {
    out << "myVector:";
    for (const T& item : myVector) {
        out << " " << item;
    }
    out << endl;
    return out;
}

void init_test() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::cout << "myVector.size(): " << myVector.size() << std::endl;
}

void add_test() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    myVector.emplace(myVector.begin() + 1, 10);
    myVector.emplace_back(100);
    myVector.emplace_back(200);
    cout << myVector << endl;
}

void storage_test() {
    std::vector<int>::size_type sz;

    std::vector<int> myVector;
    cout << "size(): " << myVector.size()
        << ", capacity():" << myVector.capacity() << endl;
    vector<int> myvector2(20);
    //myvector2.resize(20);
    cout << "size2(): " << myvector2.size()
         << ", capacity2():" << myvector2.capacity() << endl;

    sz = myVector.capacity();
    std::cout << "making myVector grow:\n";
    for (int i=0; i<100; ++i) {
        myVector.push_back(i);
        if (sz != myVector.capacity()) {
            sz = myVector.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with myVector above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }
}

void erase_test() {
    std::set<std::string> ids;
    std::vector<std::string> vecIds;
    vecIds.emplace_back("aaa");
    vecIds.emplace_back("aaa");
    vecIds.emplace_back("aaa");
    vecIds.emplace_back("aaa");
    vecIds.emplace_back("bbb");
    vecIds.emplace_back("bbb");
    vecIds.emplace_back("ccc");
    vecIds.emplace_back("aaa");
    vecIds.emplace_back("ddd");

    auto iter = vecIds.begin();
    for (; iter != vecIds.end(); ) {
        if (ids.find(*iter) != ids.end()) {
            iter = vecIds.erase(iter);
        } else {
            ids.insert(*iter);
            ++iter;
        }
    }

    iter = vecIds.begin();
    while (iter != vecIds.end()) {
        std::cout << "id in vector: " << *iter++ << std::endl;

    }
}

void data_test() {
    std::vector<int> vInt(5, 2);
    cout << "vInt.size: " << vInt.size() << ", sizeof(vInt): " << sizeof(vInt) << endl;
    cout << "vInt.size(): " << vInt.size() << ", vInt.capacity(): " << vInt.capacity() << endl;
    int aa;
}


int main() {
    //erase_test();
    //init_test();
    //add_test();
    //storage_test();
    data_test();

}


