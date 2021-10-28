#include <iostream>
using namespace std;

int main(){

    // &获取变量地址
    int i = 123;
    cout << &i << endl;

    // *存储地址的变量
    int *j;
    j = &i;
    // 等于 int *j = &i;
    //输出值
    cout << *j << endl;
    //输出地址
    cout << j << endl;

    cout << "-----------------" << endl;

    //引用
    int i2 = 10;
    double k = 12.0;

    int& _i2 = i2;
    double& _k = k;

    cout << "i:"<< i2 << "        &i:" << _i2 << "    "<< &_i2 <<endl;







    cout << "-----------------" << endl;
    int *test = new int;
    *test = 10;

    // 指针创建数组
    int *students = new int[10];
    for (size_t i = 0; i < 10; i++)
    {
        students[i] = rand();
        cout << students[i] <<endl;
    }

    // 删除指针
    delete test;
    delete [] students;

    
    system("pause");
    return 0;
}