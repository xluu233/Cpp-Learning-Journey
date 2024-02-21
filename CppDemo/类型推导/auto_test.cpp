//
// Created by A on 2023/6/30.
//

#include <iostream>
#include <vector>


auto test()
{
//    return {1,2,3}; //error，{1,2,3}类型无法推导

    auto a = {1,2,3};
    return a;
}

template<typename It>
void test(It t1, It t2){
    auto value = t1 + t2;
    std::cout << value << std::endl;
}

int main(){

    std::vector<int> v;

    auto copyV = [&v](const auto& value)
    {
        v = value;
    };

//    error，{1,2,3}类型无法推导
//    copyV({1,2,3});

    std::vector<int> v1 = {1,2,3};
    copyV(v1);

    int x1;     //success，即使未初始化，也可以编译通过，x1值是随机的
//    auto x2;    //error，auto变量必须初始化
    auto x3 = x1;   //success

    test(1.0f,2.0f);

}