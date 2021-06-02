
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>
#include <boost/asio.hpp>

class TestClass {
public:
	TestClass() {
		writeThreadpool_ = std::make_shared<boost::asio::thread_pool>(4);
	}

	int setAge(int& age) {
		std::cout << "height: " << height << ", age: " << age << std::endl;
		age = 10;
		return 0;
	}

	void callPool() {
		int localAge = 50;
		boost::asio::post(*writeThreadpool_, bind(&TestClass::setAge, this, std::ref(localAge)));
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "after post: height: " << height << ", localAge: " << localAge << std::endl;
	}
private:
	std::shared_ptr<boost::asio::thread_pool> writeThreadpool_;
	int height = 18;

};

void print1(int age) {
	std::cout << "print1 age: " << age << std::endl;
}


int main() {
	int age1 = 10;
	int age2 = 20;
	TestClass testClast;
	testClast.callPool();


}

