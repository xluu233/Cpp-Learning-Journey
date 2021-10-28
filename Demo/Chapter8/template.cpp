#include <iostream>
#include <vector>



using namespace std;


// 模板函数
template <typename T>
inline T const& Max(T &a,T&b){
    return a < b ? b : a;
}


// 模板类
template <class T>
class Stack
{
    private:
        vector<T> elems;

    public:
        void push(T &);
        T top();
        bool empty(){
            return elems.empty();
        }

};

template <class T>
void Stack<T>::push(T &elem){
    elems.push_back(elem);
}

template <class T>
T Stack<T>::top(){
    return elems.back();
}


int main(){

    int i = 20;
    int j = 30;
    cout << "Max(i, j): " << Max(i, j) << endl; 

    system("pause");
    return 0;
}