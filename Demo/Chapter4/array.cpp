#include <iostream>
#include <array>

using namespace std;

int main() {

    // 初始化：
    array<int, 5> array1;

    array<int, 5> array2{};

    array<int, 5> array3{ 0,1,2,3,4 };


    for (size_t i = 0; i < 5; i++)
    {
        cout << array1[i] << endl;
    }

    cout << "-----------------" << endl;

    for (size_t i = 0; i < 5; i++)
    {
        cout << array2[i] << endl;
    }

    cout << "-----------------" << endl;

    for (size_t i = 0; i < 5; i++)
    {
        cout << array3[i] << endl;
    }

    cout << "-----------------" << endl;
    // 常用操作

    int size = array2.size();
    cout << "size:" << size << endl;

    bool empty = array1.empty();
    cout << "is empty:" << empty << endl;

    cout << "---------数组交换--------" << endl;
    // 数组交换
    array2.swap(array3);
    for (auto i : array2) {
        cout << i << endl;
    }

    cout << "--------数组复制1---------" << endl;
    // 数组复制
    array1 = array2;
    for (auto i : array1) {
        cout << i << endl;
    }

    cout << "-------数组复制2----------" << endl;
    // 或者：
    array<int, 5> array4;
    copy(array2.begin(),array2.end(),array4.begin());
    for (auto i : array4) {
        cout << i << endl;
    }


    system("pause");
    return 0;
}