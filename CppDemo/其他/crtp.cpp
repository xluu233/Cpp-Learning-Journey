//
// Created by xlu on 2023/8/17.
//
#include <iostream>

/**
 * CRTP个人的理解是：配合模板实现的静态多态实现
 * 参考：https://zhuanlan.zhihu.com/p/476001202
 */


template<typename T>
class Base
{
public:
    void printType() const
    {
        std::string_view stringView = typeid(T).name();
        std::cout << stringView.substr(1,stringView.size()-1) << std::endl;
//        std::cout << stringView << std::endl;
    }
};

struct D1 : Base<D1> {};
struct D2 : Base<D2> {};

int main()
{
    D1 d1;
    D2 d2;

    d1.printType();
    d2.printType();
}