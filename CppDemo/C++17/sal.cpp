#include <iostream>
#include <cassert>
#include <sal.h>

void test([[maybe_unused]] std::string* str) {
//    std::cout << "str1:" << *str << std::endl;
    std::cout << "test1" << std::endl;
};

void test2([[maybe_unused]] std::string* str) {
//    std::cout << "str2:" << *str << std::endl;
    std::cout << "test2" << std::endl;
};

void test3(_In_ std::string* str) {
    std::cout << "test3  " << *str << std::endl;
};

void test4(_In_ [[maybe_unused]] std::string* str) {
    std::cout << "test4" << std::endl;
};

void test5([[maybe_unused]] _In_  std::string* str) {
    std::cout << "test5" << std::endl;
};


int main()
{
    std::string name = "test";
    test(&name);
    test2(&name);
    test3(&name);
    test4(&name);
    test5(&name);
}
