#include <iostream>
#include <string.h>
using namespace std;

class Box
{
    private:
        int i = 0;
    public:
        Box(int i){
            this->i = i;
        };
        ~Box(){

        };
        void print(){
            cout << i <<endl;
        };
        Box operator++(){
            this->i += 2;
            return *this;
        };
        Box operator++(int){
            this->i += 1;
            return *this;
        };
        friend Box operator--(Box &box){
            --box.i;
            return box;
        };
        friend Box operator--(Box &box,int){
            --box.i;
            return box;
        };
        Box operator+(const Box &box){
            int i = this->i + box.i;
            Box temp(i);
            return temp;
        };
        Box operator-(const Box &box){
            this->i -= box.i;
            return *this;
        };
        friend Box operator*(Box &box1,Box &box2){
            Box temp(box1.i * box2.i);
            return temp;
        }
        Box operator=(Box &box){
            this->i = box.i;
            return *this;
        }
        void operator()(int i){
            this->i = i;
        }
};

// 人员基本信息
struct People
{
    int id;
    string name;
    // People(int i,string str){
    //     id=i;
    //     name = str;
    // }
};

// 工程师类
class Engineer
{
    private:
        int size = 0;   //初始化容量
        int n = 0;  //实际加入容量
        People *people;
    public:
        Engineer(int size){
            this->size = size;
            n = 0;
            people = new People[size];
        };
        People* operator[] (int id){
            People *temp;

            // 查找是否存在
            for (temp=people; temp < people+n; temp++)
            {
                if (temp->id == id)
                {
                    return temp;
                }
            }

            // 创建新值
            temp = people+n++;
            temp->id = id;
            temp->name = "unknow";
            return temp;
        }
        ~Engineer(){
            cout<<"deleted engineer"<<endl;
        };
};

class X{
	public:
		int operator() (int i=0)
		{ cout << "X::operator(" << i << ")" << endl; return i; };
		int operator() (int i, int j)
		{ cout << "X::operator(" << i << "," << j << ")" << endl; 
				return i; };
		int operator[] (int i)
		{ cout << "X::operator[" << i << "]" << endl; return i; };
		int operator[] (char * cp)
		{ cout << "X::operator[" << cp << "]" << endl; return 0; };
};

int main(){

	X obj;
	int i = obj (obj (1), 2);
	int a = obj[i];
	int b = obj["abcd"];
	
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    // Box box1(1),box2(2),box3(0);
    // box1(123);
    // box1.print();
    // //或者显示写法：
    // box1.operator()(1314);
    // box1.print();

    // box2.print();
    // box3.print();


    // Engineer engineer(10);

    // for (size_t i = 0; i < 5; i++)
    // {
    //    engineer[i]->name = "Engineer-" + to_string(i);
    // }
    
    // for (size_t i = 0; i < 10; i++)
    // {
    //     cout<< engineer[i]->id <<"   "<< engineer[i]->name <<endl;
    // }
    

    system("pause");
    return 0;
}