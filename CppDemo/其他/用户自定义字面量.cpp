//
// Created by xlu on 2023/5/1.
//
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

std::string operator ""_r(const char* str,size_t size){
    std::cout << str << "  size:" << size << std::endl;
    return str;
}

int main(){
    std::cout <<   "211231 "_r << std::endl;

    auto h = 12h;
    auto m = 30min;
    auto s = 60s;
}