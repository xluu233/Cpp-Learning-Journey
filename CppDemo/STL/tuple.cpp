//
// Created by xlu on 2023/7/29.
//
#include <iostream>
#include "container.h"
#include <tuple>


auto get_tuple_1(){
    return std::make_tuple(1.0,'A',"Testing123");
}

tuple<int,const char *> get_tuple_2(){
    return std::make_tuple(1,"ABC");
}

//tuple作为函数返回值的时候的不同写法
auto get_tuple_3() -> tuple<int,int,int>{
    return {1,2,3};
}

int main(){

    auto tp1 = get_tuple_1();
    auto tp2 = get_tuple_2();
    auto tp3 = get_tuple_3();

    cout << "tp1:   " << std::get<0>(tp1)
            << "  " << std::get<1>(tp1)
            << "  "<< std::get<2>(tp1) << endl;

    //利用tie解包
    int i;
    std::string str;
    std::tie(i,str) = tp2;
    cout << "tp2:   " << i << "     " << str << endl;



}
