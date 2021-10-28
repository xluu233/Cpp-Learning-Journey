#include <iostream>
using namespace std;


struct People
{
    int id;
    string name;
    float weight;
} people {
    1,"xlu",140.0f
};

//结构体类型别名
typedef struct
{
    int i;
    double j;
} Book ;

typedef long int* pint32;

int main(){

    //类型别名指针
    long int li32 = 123;
    pint32 _pint32 = &li32;

    // 结构体指针
    struct People *xlu;

    // c++11
    People test {
        2,"hah",120.0f
    };
    
    xlu = &test;

    // 类型别名创建结构体
    Book book1,book2;

    // People people;
    // people.id = 1;
    // people.name = "xiaoming";
    // people.weight = 130.0f;


    cout << people.name << endl;
    cout << test.name << endl;


    //结构数组
    People peopleArr[2] = {
        {
            1,"xlu",140.0f
        },
        {
            1,"xlu",140.0f
        }
    };


    system("pause");
    return 0;
}