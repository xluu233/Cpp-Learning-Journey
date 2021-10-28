#include <iostream>
using namespace std;

// 共用体包含多种类型成员，但同时只能使用一种
union ONE
{
    int i;
    float j;
};


//配合结构体使用：
struct PEOPLE
{
    string name;
    union TEST
    {
        int id;
        float id_f;
    } test;
    
};

//匿名共用体：
struct PEOPLE2
{
    string name;
    union {
        int id;
        float id_f;
    };
};

int main(){

    ONE one;
    one.i = 123;
    cout << one.i <<endl;

    one.j = 1.0f;
    cout << one.i <<endl;   //one.i将会丢失
    cout << one.j <<endl;

    system("pause");
    return 0;
}