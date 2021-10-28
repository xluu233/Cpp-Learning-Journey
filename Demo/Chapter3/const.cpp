// 基本数据类型展示

#include <iostream>
using namespace std;


int* const fun1(){
    int k = 122;
    // int *ptr = &i;
    return &k;
}

void fun2(const int i){
    cout<<i<<endl;
    //i = 123;
    cout<<i<<endl;
}

void fun3(char* const str){

}

class Apple{
    public:
        int i =0;
        const int j = 10;
}
int main(){

    const int i = 123;
    int j = 12;

    const int *ptr;
    // error,不可以直接操作*ptr
    // *prt = 10;

    // success
    ptr = &j;
    // 不可以再赋值
    // ptr = &i;
    cout << *ptr <<endl;

    // success
    int* const ptr2 = &j;
    cout << *ptr2 <<endl;

    const int* const ptr3 = &i;
    cout << *ptr3 <<endl;

    cout<<"--------------"<<endl;

    int* ptr4;
    ptr = fun1();
    ptr = &i;
    cout << *ptr4 << endl;

    system("pause");
    return 0;
}

