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

void shared_ptr_test() {

    // std::shared_ptr<int> pInt(new int(5));
    std::shared_ptr<int> pInt;
    // bool needSync = current_sync_client ? true : false;
    bool aa = pInt ? true : false;
    std::cout << "aa: " << aa << std::endl;

}

int main() {
    shared_ptr_test();
}


