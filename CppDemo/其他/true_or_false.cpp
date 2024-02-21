//
// Created by xlu on 2023/9/15.
//
#include <iostream>

int main()
{
    int *i = nullptr;
    if (i)
    {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    if (1)
    {
        std::cout << "1 == true" << std::endl;
    }

}