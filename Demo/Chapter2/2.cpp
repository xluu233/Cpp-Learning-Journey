#include <iostream>

using namespace std;

class Fruit
{
    private:
    public:
        Fruit();
        ~Fruit();
        virtual void fuck() = 0;

        void fuck1(){
            cout <<"fuck 1"<<endl;
        }

        virtual void fuck2(){
            cout <<"fuck 2"<<endl;
        }
};

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}


class Apple: public Fruit
{
    private:
        
    public:
        Apple();
        ~Apple();

        void fuck(){
            cout << "fuck apple"<<endl;
        };

        // void fuck1(){
        //     cout << "fuck apple 11"<<endl;
        // };

        void fuck2(){
            cout << "fuck apple 22"<<endl;
        };

};

Apple::Apple()
{
}

Apple::~Apple()
{
}

int main(){

    Apple apple;
    apple.fuck();
    apple.fuck1();
    apple.fuck2();

    return 0;
}