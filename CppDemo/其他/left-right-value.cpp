//
// Created by xlu on 2023/7/29.
//
#include <iostream>
#include <string>

void refrence(std::string& str){
    std::cout << "left: " << str << std::endl;
}

void refrence(std::string&& str){
    std::cout << "right: " << str << std::endl;
}

int main(){
    std::string lv1 = "string,"; //left

//    std::string&&  r1 = lv1;    //非法
    std::string && rv1 = std::move(lv1);    //必须通过move将left转换为right
    std::cout << rv1 << std::endl;

    const std::string & lv2 = lv1 + lv1;    //const常量能延长临时变量生命周期
    std::cout << lv2 << std::endl;

    std::string&& rv2 = lv1 + lv1; //合法，右值引用延长对象生命周期
    rv2 += "Test";  //合法
    std::cout << rv2 << std::endl;

    //输出为左值，
    refrence(rv2);

//    std::string str3 = std::move(rv1);
//    std::string  str3 = std::move(lv1);

}