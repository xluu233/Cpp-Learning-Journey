#include <iostream>
using namespace std;


class Base
{
    private:
        int i = 0;
    public:
        Base(){

        };
        virtual ~Base(){
            cout<<"deleted Base"<<endl;
        };
        virtual void fun1() = 0;
        virtual void fun2(){
            cout <<"Base::fun2()"<<endl;
        };

};

class A:virtual public Base
{
    private:
        int j = 0;
    public:
        A():Base(){
            
        };
        ~A(){
            cout<<"deleted A"<<endl;
        };
        void fun1(){
            cout<<"A::fun1()"<<endl;
        }

        virtual void fun2() override{
            cout<<"A::fun2()"<<endl;
        };
};

class B: public A
{
private:
    int j = 0;
public:
    B():Base(){

    };
    ~B(){
        cout<<"deleted B"<<endl;
    };
    void fun1(){
        cout<<"B::fun1()"<<endl;
    }

    void fun2(){
        cout<<"B::fun2()"<<endl;
    };
};



int main(){

    Base *base = new A();
    base->fun1();
    base->fun2();
    delete base;

    base = new B();
    base->fun1();
    base->fun2();
    delete base;

    return 0;
}