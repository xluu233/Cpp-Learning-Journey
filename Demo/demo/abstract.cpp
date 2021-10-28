#include <iostream>
#include <string.h>
using namespace std;

struct People
{
    int id;
    string name;
};

class Base
{
    private:
        People *people;
    public:
        Base(){
            cout<<"create Base"<<endl;
        };
        // Base(int id,string name){
        //     people = new People();
        //     people->id = id;
        //     people->name = name;
        //     cout<<"create Base"<<endl;
        // };
        ~Base(){
            delete people;
            cout << "deleted Base" << endl;
        };
        virtual void fun() = 0;

        virtual void fun2(){
            cout << "Base::fun2()" << endl;
        };
};


class A:virtual public Base
{
    private:
        int a = 0;
    public:
        A(int i):Base(){
            a = i;
            cout<<"create A"<<endl;
        };
        ~A(){
            cout << "deleted A" << endl;
        };
        void fun(){
            cout << "funA"<<endl;
        }
};

class B:public A,virtual public Base
{
    private:
        int b = 0;
    public:
        B(int i,int j):A(j){
            cout<<"create B"<<endl;
            b = i;
        };
        ~B(){
            cout << "deleted B" << endl;
        };
        void fun(){
            cout << "funB"<<endl;
        }
        virtual void funB(){
            cout << "funBBBBB"<<endl;
        };
        void fun2(){
            cout << "B::fun2()" << endl;
        };
};


int main(){
    A a(1);

    Base *base;
    base = &a;
    base->fun();
    
    //或者：
    Base *base2 = new B(123,322);
    base2->fun();
    base2->fun2();


    // delete base;
    // delete base2;
    return 0;
}