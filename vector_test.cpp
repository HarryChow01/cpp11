#include <vector>
#include <set>
#include <iostream>

using namespace std;

template<class T>
ostream& operator<<(ostream& out, std::vector<T>& myvector) {
    out << "myvector:";
    for (const T& item : myvector) {
        out << " " << item;
    }
    out << endl;
    return out;
}

void init_test() {
    std::vector<int> myvector = {1, 2, 3, 4, 5};
    std::cout << "myvector.size(): " << myvector.size() << std::endl;
}

void add_test() {
    std::vector<int> myvector = {1, 2, 3, 4, 5};
    myvector.emplace(myvector.begin() + 1, 10);
    myvector.emplace_back(100);
    myvector.emplace_back(200);
    cout << myvector << endl;
}

void storage_test() {
    std::vector<int>::size_type sz;

    std::vector<int> myvector;
    cout << "size(): " << myvector.size()
        << ", capacity():" << myvector.capacity() << endl;
    vector<int> myvector2(20);
    //myvector2.resize(20);
    cout << "size2(): " << myvector2.size()
         << ", capacity2():" << myvector2.capacity() << endl;

    sz = myvector.capacity();
    std::cout << "making myvector grow:\n";
    for (int i=0; i<100; ++i) {
        myvector.push_back(i);
        if (sz != myvector.capacity()) {
            sz = myvector.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with myvector above
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

int main() {
    //erase_test();
    //init_test();
    //add_test();
    storage_test();
}


