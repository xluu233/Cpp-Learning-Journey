#include <iostream>
using namespace std;


class Box{

    // 私有成员
    private:
        double length;
        double width;
        static int money;

    // 公共成员
    public:
        int size;
        // 构造函数：
        Box();
        Box(double _length,int _size);
        //Box(double _length,int _age);
        // 析构函数：
        ~Box();
        // 友元函数
        friend void printSth(Box box);
        // 静态函数
        int getMoney(){
            return money;
        }

    // 内部定义成员函数
    double getV(){
        return length*width;
    }

    // 外部定义成员函数
    void setLength(double _length);
    void setWidth(double _width);

    // 派生成员
    protected:
        int age;

        void prin(){
            cout << this->length <<endl;
        }
};

// 静态成员初始化
int Box::money = 10;


// 外部定义成员函数
void Box::setLength(double _length){
    length = _length;
}

void Box::setWidth(double _width){
    width = _width;
}


// 派生类
class SmallBox:Box
{

    public:
        void setSmallAge(int _age);
        int getSmallAge();

};

void SmallBox::setSmallAge(int _age){
    age = _age;
    //size = 1;
}

int SmallBox::getSmallAge(){
    return age;
}

// 构造函数
Box::Box(){
}

Box::Box(double _length,int _size){
    length = _length;
    size = _size;
}

// Box::Box(double _length,int _age){
//     length = _length;
//     age = _age;
// }

// 析构函数
Box::~Box(){
    cout << "box deleted" <<endl;
}


//友元函数
void printSth(Box box){

    // 在Box类中设置了友元函数，所以能访问Box的所有成员
    cout << "friend:" << box.length << endl;
}

// 内联函数
inline int Max(int i,int j){
    return i >= j ? i : j;
}


int main(){

    Box box;
    box.setLength(100);
    box.setWidth(20);

    cout << "box:" << box.getV() << endl;
    
    Box box1(12,12);
    cout << "box1:" << box1.size << endl;

    //delete &box1;

    cout <<"---------------"<<endl;
    printSth(box);

    // 类指针
    Box *ptrBOX;
    ptrBOX = &box;

    cout << ptrBOX->size <<endl;


    //system("pause");
    return 0;
}
