#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> test;

    for (size_t i = 0; i < 100; i++)
    {
        test.push_back(i);
    }
    
    for (size_t i = 0; i < 50; i++)
    {
        test.pop_back();
    }
    
    // 更新数据
    test[10] = 123;
    test[11] = 112;
    //更新第13个数据
    test.insert(test.begin()+12,110);

    // 删除数据
    // 删除test[1]
    test.erase(test.begin()+1);

    // 普通遍历方式
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << test[i] << endl;
    }
    


    cout<< "-------------------" <<endl;

    cout << "test begin:" << *test.begin() <<endl;
    // 数组的最后一个单元+1的指针
    cout << "test end:" << *test.end() <<endl;

    cout << "test front:" << test.front() <<endl;
    cout << "test back:" << test.back() <<endl;

    cout << "test &front:" << &test.front() <<endl;
    cout << "test &back:" << &test.back() <<endl;

    // 迭代器,此时i的类型为：vector<int>::iterator
    for (auto i = test.begin(); i != test.end(); i++)
    {
        cout<< *i <<endl;
    }
    

    cout<< "-------------------" <<endl;

    // 复制数组:
    vector<int> test3;
    test3.insert(test3.end(),test.begin(),test.end());
    cout <<"test3.size:" << test3.size() <<endl;
    
    // 或者：
    vector<int> test4(test);
    cout <<"test4.size:" << test4.size() <<endl;


    // 交换数组：
    vector<int> test2;
    // swap(test2,test);
    // 或者：
    test2.swap(test);
    cout <<"test2.size:" << test2.size() <<endl;

    system("pause");
    return 0;
}