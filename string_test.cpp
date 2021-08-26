
#include <iostream>
#include <string>
#include <memory>
#include <map>

std::map<std::string, std::shared_ptr<std::string>> gMap;
std::map<std::string, std::string> gMap2;

void string_test1() {
    std::string str1 = "abc";
    std::cout << "sizeof(str1): " << sizeof(str1) << std::endl;
    std::cout << "str1 address: " << &str1 << ", str1 data address: " << static_cast<const void *>(str1.data()) << std::endl;
    // std::string str2 = std::move(str1);
    std::string str2 = str1;
    std::cout << "sizeof(str2): " << sizeof(str2) << std::endl;
    std::cout << "str1 address: " << &str1 << ", str1 data address: " << static_cast<const void *>(str1.data()) << std::endl;
    std::cout << "str2 address: " << &str2 << ", str2 data address: " << static_cast<const void *>(str2.data()) << std::endl;
    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;
    std::shared_ptr<std::string> pStr = std::make_shared<std::string>(str2);
    std::cout << "*pStr: " << *pStr << std::endl;
    gMap.emplace("aa", pStr);
    gMap2.emplace("aa", str2);
}

void string_test2() {
    auto it = gMap.find("aa");
    const auto& str1 = *(it->second);
    std::cout << "str1 address: " << &str1 << ", str1 data address: " << static_cast<const void *>(str1.data()) << std::endl;
    auto it2 = gMap2.find("aa");
    const auto& str2 = it2->second;
    std::cout << "str2 address: " << &str2 << ", str2 data address: " << static_cast<const void *>(str2.data()) << std::endl;
}

void string_test3() {
    std::string str1 = "abc_123";
    auto pos = str1.find('_');
    std::string value;
    if (pos == std::string::npos) {
        value = str1;
    } else {
        value = str1.substr(0, pos);
    }
    std::cout << value << std::endl;
}

void string_test4() {
    int xx = 0x41424344;
    std::string str1 = std::string(reinterpret_cast<char*>(&xx), sizeof(int));
    std::cout << "str1: " << str1 << std::endl;
    const int* yy = reinterpret_cast<const int*>(str1.data());
    std::cout << "*yy: " << std::hex << *yy << std::endl;
}

int main() {
    string_test1();
    // string_test2();
    // string_test4();
    return 0;
}

