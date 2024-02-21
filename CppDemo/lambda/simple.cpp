#include <iostream>

using namespace std;


// 参考：https://changkun.de/modern-cpp/zh-cn/03-runtime/

int main(){

    auto add = [](auto x, auto y) {
        return x+y;
    };

    cout << add(1, 2) << endl;
    cout << add(1.1, 2.2) << endl;

    
    int i = 0;
    auto res = [i](int x, int y) -> int{
        return i*(x+y);
    };
    //因为i是0 ，所以结果一直是0
    cout << res(1,2) << endl;
    

}