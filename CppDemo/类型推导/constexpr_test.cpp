//
// Created by A on 2023/6/29.
//
#include <iostream>
#include <array>

//https://github.com/CnTransGroup/EffectiveModernCppChinese/blob/master/src/3.MovingToModernCpp/item15.md

/**
 * constexpr作用与函数的时候，表示在编译器可以确定其值，否则编译会不通过
 * @param a
 * @param b
 * @return
 */
constexpr int pow(int a, int b) noexcept{
    return a+b;
}


//C++11中，constexpr函数的代码不超过一行语句：一个return。听起来很受限，但实际上有两个技巧可以扩展constexpr函数的表达能力。
//第一，使用三元运算符“?:”来代替if-else语句，第二，使用递归代替循环。因此pow可以像这样实现：
//在C++14中，constexpr函数的限制变得非常宽松了
constexpr int pow2(int base, int exp) noexcept
{
    return (exp == 0 ? 1 : base * pow(base, exp - 1));
}


int main(){

    int n = 5;
    // constexpr auto n1 = n;    //error n1不是编译器常量
    constexpr auto n2 = 5;  //正确,5是编译器常量

    std::array<int, pow(3,n2)> arr;
    //输出8，编译正确
    std::cout << arr.size() << std::endl;
}