//
// Created by xlu on 2023/4/30.
//
#include <iostream>
#include <functional>


struct Test{

    void f(){
        std::cout << "f" << std::endl;
    };

    //非静态成员函数重载
    void f(int){
        std::cout << "int f" << std::endl;
    }

};

void f2(void(Test::*p)(), Test& t){
    (t.*p)();
}

void f3(void(Test::*p)(int), Test* t,int n){
    (t->*p)(n);
}


int main(){

    //p就是指向Test::f的成员函数指针
    void(Test::*p)() = &Test::f;

    //调用
    Test t;
    (t.*p)();

    f2(&Test::f,t);
    f3(&Test::f,&t,100);

    Test t2;
    auto func = static_cast<void(Test::*)(int)>(&Test::f);
    auto n = std::bind(func,&t2,10);
    n();
}