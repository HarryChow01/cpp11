#include <memory>
#include <iostream>

void uniqueptr_test() {
    // std::unique_ptr<int> pInt = new int(5);  // error, assign is deleted
    std::unique_ptr<int> pInt(new int(5));
    std::cout << "*pInt: " << *pInt << std::endl;
    // std::unique_ptr<int> pInt2(pInt);  // error, copy constructor is deleted
    std::unique_ptr<int> pInt2 = std::move(pInt);
    std::cout << "*pInt2: " << *pInt2 << std::endl;
    std::cout << "*pInt: " << *pInt << std::endl;   // not executed

}

int main() {
    uniqueptr_test();
}


