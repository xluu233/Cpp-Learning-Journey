#include <iostream>
using namespace std;


auto i = 10;

//register int test;

int main(){

    register int test = -1;
    auto count = 12;

    cout << i << endl;

    // 为什么有时候不用int，而是用size_type或者size_t:
    // 与int固定四个字节不同有所不同,size_t的取值range是目标平台下最大可能的数组尺寸,
    // 一些平台下size_t的范围小于int的正数范围,又或者大于unsigned int. 
    // 使用Int既有可能浪费，又有可能范围不够大。
    for (size_t i = 0; i < count; i++)
    {
        if (i==3)
        {
            continue;
        }
        
        cout << i << endl;

        if (i > 5)
        {
            break;
        }
        
    }


    for (size_t i = 0; i < count; i++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            if (i == 5)
            {
                //退出循环
                goto stop;
            }

            cout << i << endl;
        }
        
    }
    stop:


    system("pause");
    return 0;
}