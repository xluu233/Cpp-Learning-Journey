#include <iostream>
using namespace std;


// 指针指向数组
void function(int *p){

}

// 大小为10的数组
void function2(int p[10]){

}

// 未定义数组大小
void function3(int p[]){

}


int* function4(int size){
    int *arr;
    arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = i * 10;
    }
    return arr;
}


int main(){

        
    int *p;
    p = function4(10);

    for (size_t i = 0; i < 10; i++)
    {
        cout<< p[i] <<endl;
    }
    
    system("pause");
    return 0;
}