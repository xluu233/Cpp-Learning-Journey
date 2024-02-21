#include <iostream>
#include <tuple>
#include <string>

using namespace std;

auto getTuple(int i)
{
    // 返回类型被推断为 std::tuple<int, char, std::string>
    switch (i)
    {
    case 0:
        return std::make_tuple(80,'A',"张三");
        break;
    case 1:
        return std::make_tuple(100,'B',"小卢");
        break;
    default:
        return std::make_tuple(120,'A',"李四");
        break;
    }
}

int main(){

    auto tu = getTuple(0);
    cout << "0: " << std::get<0>(tu) << endl;
    cout << "1: " << std::get<1>(tu) << endl;
    cout << "2: " << std::get<2>(tu) << endl;



    int age;
    char sex;
    string name;

    // 元组拆包
    std::tie(age,sex,name) = getTuple(1);
    cout << "age: " << age << endl;
    cout << "sex: " << sex << endl;
    cout << "name: " << name << endl;

}