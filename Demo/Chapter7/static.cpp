#include <iostream>
using namespace std;

class Box
{
    private:
        static int money;
        // 初始化次数
        static int initCount;
        static int jk = 123;
    public:
        void setMoney(int _money){
            this->money = _money;
        }
        int getMoney(){
            cout << "init:"<<initCount<<"    money:"<<money <<endl;
            return money;
        }
        Box(){
            initCount++;
        }
        // 静态函数
        static int getCount(){
            return initCount;
        }
};

int Box::money = 123;
int Box::initCount = 0;

// 
int main(){

    Box box1;
    box1.setMoney(1);
    box1.getMoney();

    Box box2;
    //box2.setMoney(2);
    box2.getMoney();

    //Box::getCount();
    cout << Box::getCount() <<endl;
    cout << box2.getCount() <<endl;

    static const int ijk = 123;
    cout<<"ijk:"<<ijk <<endl;
    system("pause");
    return 0;
}