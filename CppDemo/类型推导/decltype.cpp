//
// Created by xlu on 2023/7/25.
//
#include <iostream>

template<typename T, typename  U>
auto add(T t1, U u1) -> decltype(u1 + t1){
    return  t1 + u1 ;
}

//C++14支持返回值类型推导
template<typename T, typename  U>
auto add2(T t1, U u1){
    return  t1 + u1 ;
}


int main() {

    std::cout << add(1,2.2) << std::endl;
    std::cout << add2(1,2.2) << std::endl;

}