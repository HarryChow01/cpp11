
#include <iostream>
#include <string>
#include <memory>
#include <map>

std::map<std::string, std::shared_ptr<std::string>> gMap;

void string_test1() {
    std::string str1 = "abc";
    std::cout << "sizeof(str1): " << sizeof(str1) << std::endl;
    std::cout << "str1 address: " << &str1 << ", str1 data address: " << static_cast<const void *>(str1.data()) << std::endl;
    std::string str2 = std::move(str1);
    std::cout << "sizeof(str2): " << sizeof(str2) << std::endl;
    std::cout << "str2 address: " << &str2 << ", str2 data address: " << static_cast<const void *>(str2.data()) << std::endl;
    std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;
    std::shared_ptr<std::string> pStr = std::make_shared<std::string>(str2);
    std::cout << "*pStr: " << *pStr << std::endl;
    gMap.emplace("aa", pStr);
}

void string_test2() {
    auto it = gMap.find("aa");
    const auto& str1 = *(it->second);
    std::cout << "str1 address: " << &str1 << ", str1 data address: " << static_cast<const void *>(str1.data()) << std::endl;
}

int main() {
    string_test1();
    string_test2();
    return 0;
}

