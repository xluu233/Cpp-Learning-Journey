#include <iostream>
using namespace std;

class Shape{
    private:
        int length;
        int width;
    public:
        virtual int area(){
            cout << "Shape" << endl;
        }
        // 纯虚函数
        // virtual int area() = 0;
};

class Rectangle : public Shape{
    public:
        int area(){
            cout << "Rectangle" << endl;
        }
};


int main(){

    Shape *shape;
    Rectangle rec;

    shape = &rec;
    shape->area();

    system("pause");
    return 0;
}