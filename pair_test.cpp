#include <iostream>
using namespace std;

void pair_test() {
    std::pair<int, int> intPair = std::make_pair(5, 10);
    std::cout << "intPair.first: " << intPair.first << ", intPair.second: " << intPair.second << std::endl;
}

int main() {
    pair_test();
}


