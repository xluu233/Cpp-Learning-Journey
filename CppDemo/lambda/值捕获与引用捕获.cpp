#include <iostream>

using namespace std;

// 值捕获
void lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value]
    {
        return value*2;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 1, 而 value == 100.
    // 因为 copy_value 在创建时就保存了一份 value 的拷贝
}

// 引用捕获
void lambda_reference_capture()
{
    int value = 1;
    auto copy_value = [&value]
    {
        return value*2;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 100, value == 100.
    // 因为 copy_value 保存的是引用
}


void test(){
    int value = 1;
    auto copy_value = [&value](int x,int y) -> int
    {
        return value + x*y;
    };
    //value = 100;
    auto stored_value = copy_value(2,2);
    std::cout << "stored_value = " << stored_value << std::endl;
}

int main()
{
    lambda_value_capture();
    lambda_reference_capture();
    test();
}