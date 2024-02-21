//
// Created by xlu on 2023/7/25.
//
#include <iostream>

using namespace std;

constexpr int int_arr_len(){
    return 5;
}

int main()
{
    int i = 2;
    char arr1[i];


    const int len2 = i + 1;
    char arr2[len2];    //非法，但是编译器支持

    constexpr int len3 = 1 + 2+ 3;
    char arr3[len3];    //合法


}
