//
// Created by xlu on 2023/8/1.
//
#include <iostream>

using namespace std;


int test(int i)
{
    return ++i;
}

//函数指针
int (*p)(int) = &test;

//typedef定义一种类型的函数指针
typedef int (*fp)(int);

//函数指针传参
int test2(fp fp1, int i)
{
    cout << fp1(++i) << endl;
    return i;
}


int main(){

    //调用函数指针
    cout << p(1) << endl;

    //typedef定义的函数指针
    fp f = &test;
    cout << f(1) << endl;

    //函数指针作为参数，可以视为回调函数
    test2(f,2);

}