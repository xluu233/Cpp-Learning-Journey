//
// Created by xlu on 2023/7/30.
//
#include <iostream>
#include <memory>


//手动实现make_unique

template<typename T,typename ...Args>
std::unique_ptr<T> make_unique2(Args&& ...args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


int main(){

}