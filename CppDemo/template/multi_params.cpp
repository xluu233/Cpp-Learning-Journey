#include <iostream>

// 尝试用折叠表达式实现用于计算均值的函数，传入允许任意参数。


template<typename ... T>
auto average(T ... t) {
    return (t + ... ) / sizeof...(t);
}

int main() {
    std::cout << average(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}