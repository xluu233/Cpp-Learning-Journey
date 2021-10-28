#include <iostream>
using namespace std;


class Base
{
    private:
        int i;
    public:
        int j;
    protected:
        int k;
};

class Activity : Base
{
    private:

    public:
        // int getI(){
        //     return i;
        // }
        int getJ(){
            return j;
        }
        int getK(){
            return k;
        }

};

// 继承类型
class test: public Base{

};

class test2: protected Base{

};

class test3: private Base{

};

// 多继承
class test4 : Base,test2{

};

class test5 : public Base,private test2,protected test3{

};

int main(){

    

    system("pause");
    return 0;
}