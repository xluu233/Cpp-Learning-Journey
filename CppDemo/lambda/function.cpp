#include <iostream>
#include <functional>

using foo = void(int);

// 参数列表中定义的函数类型 foo 被视为退化后的函数指针类型 foo*
void func(foo f){
    f(1);
}

//void func2((*)void(int) f){
//    f(1);
//}

using namespace std;

int main(){

    // f就是foo的实现
    auto f = [](int i){
        cout << i << endl;
    };
    // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
    func(f);
    f(1);

}