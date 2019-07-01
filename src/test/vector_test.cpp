#include <vector>
#include <iostream>

using namespace std;

void printVector(const vector<int>& vec) {
    for (auto& item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

int test1() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, };
    //vector<int> vec(begin(a), end(a));
    vector<int> vec;
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    printVector(vec);
}

void test2() {
    vector<int> v;
    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
    v.reserve(10);
    cout << "v[5]: " << v[5] << endl;   // 数组不检查越界
    //cout << "v.at(5): " << v.at(5) << endl;  // out_of_range
    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
    v.resize(10);
    v.push_back(0);
    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;

}

int main() {
    test1();
    test2();
    return 0;
}

