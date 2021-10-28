#include <iostream>
#include <vector>

using namespace std;

int main(){

    int test[3][4];
    int array[3][4] = {
        {1,2,3,123},
        {123,123,234},
        {12313,123123,12323}
    };

    cout << "array[0]:" << array[0] << endl;

    for (size_t i = 0; i < 4; i++)
    {
        cout << array[0][i] << endl;
    }
    
    cout<<"---------------"<<endl;

    // 一维数组指针，指向array首地址
    int (*p)[4] = array;
    for (size_t i = 0; i < 4; i++)
    {
        cout << (*p)[i] << endl;
    }

    // 这里就是之前降到的“数组指针”的作用
    int (*pp)[3][4] = &array;
    
    cout<<"---------------"<<endl;

    // 指向array[0]数组的指针
    int *p0 = array[0];
    for (size_t i = 0; i < 4; i++)
    {
        cout<<p0[i]<<endl;
    }
    
    // 指向array[1]数组的指针
    int *p1 = array[1];
    for (size_t i = 0; i < 4; i++)
    {
        cout<<p1[i]<<endl;
    }

    system("pause");
    return 0;
}