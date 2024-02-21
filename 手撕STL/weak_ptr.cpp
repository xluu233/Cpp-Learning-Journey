//
// Created by xlu on 2023/8/13.
//
#include <iostream>
#include <memory>


int main()
{
    int i = 110;
    std::shared_ptr<int> sp1(&i);
    std::weak_ptr<int> wp1(sp1);

    auto sp2 = wp1.lock();

    std::cout << *sp2.get() << std::endl;

    return 0;
}