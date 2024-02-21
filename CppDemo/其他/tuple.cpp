//
// Created by xlu on 2023/7/25.
//
#include <iostream>
#include <tuple>

std::tuple<int, float, std::string> f() {
    return std::make_tuple(1,2.3f,"abc");
}

int main(){
    auto [x,y,z] = f();
    std::cout << x << " \n " << y  << " \n " << z << std::endl;

}