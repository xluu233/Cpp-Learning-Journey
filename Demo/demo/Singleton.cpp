#include <iostream>
using namespace std;


class singleton {
    private:
        singleton() {}
        static singleton *p;
    public:
        static singleton *instance();
        void show(){
            cout << "hahah" <<endl;
        }
};

singleton *singleton::p = nullptr;

singleton* singleton::instance() {
    if (p == nullptr)
        p = new singleton();
    return p;
}


int main(){

    // singleton::instance->show();

    system("pause");
    return 0;
}