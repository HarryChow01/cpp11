
#include <memory>
#include <unordered_map>
#include <iostream>


using namespace std;

struct xx {
    //std::unique_ptr<int> pInt;
    int age = 0;
};

void map_test() {
    std::unordered_map<string, xx> testMap;
    testMap["aa"] = xx();

}

int main() {

    return 0;
}


