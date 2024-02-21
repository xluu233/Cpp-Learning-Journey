//
// Created by xlu on 2023/10/24.
//
#include "container.h"


int main()
{
    int arr[10] = {0,1,2,3,4,5,6,255,1024,-1};

    std::vector<int> v1(arr,arr+10);
    printVec(v1);

//    for (int i = 0; i < 10; ++i) {
//        std::cout << &arr[i]<< "   -    " << &v1[i] << std::endl;
//    }

//    std::vector<int> v2(v1);
    std::vector<int> v2(std::move(v1));

    for (int i = 0; i < 10; ++i) {
        std::cout << &v1[i]<< "   -    " << &v2[i] << std::endl;
    }
}