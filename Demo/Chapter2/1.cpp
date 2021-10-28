
#include <iostream>
using namespace std;

class Fruit
{
    private:
        int count = 0;
    public:
        Fruit();
        ~Fruit();

        void add(int i);

        int getCount(){
            return count;
        }

        // friend void printF(Fruit ft);
        friend void printF(Fruit &ft);

};


Fruit::Fruit()
{
    cout << "create fruit" << endl;
}


Fruit::~Fruit()
{
    cout <<"fruit deleted"<<endl;
}

void Fruit::add(int i){
    count = count + i;
}

// void printF(Fruit ft){
//     cout << ft.count <<endl;
// }

void printF(Fruit &ft){
    cout << ft.count <<endl;
}



int main(){

    Fruit fruit;
    fruit.add(1);
    cout<<fruit.getCount()<<endl;

    printF(fruit);

    return 0;
}