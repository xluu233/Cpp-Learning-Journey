//
// Created by A on 2023/6/29.
//
#include <iostream>
#include <array>

/**
 * 一般数组在形参中都会被作为指针使用，但是可以接受指向数组的引用！
 * 修改模板参数为引用，我们可以得到真正的数组，这样还可以得到数组大小
 * constexpr使得结果在编译器可用
 * @tparam T 被推导为数组，而不是数组指针
 * @tparam Size
 * @return
 */
template<typename T, std::size_t Size>
constexpr std::size_t  getArraySize(T (&)[Size]){
    return Size;
}

int main(){
    int arr[] = {1,3,34,43,123};
    std::cout << getArraySize(arr) << std::endl;

    //成熟的程序员会使用array代替原生数组
    std::array<int, getArraySize(arr)> arr2{};
    std::cout << arr2.size() << std::endl;
}