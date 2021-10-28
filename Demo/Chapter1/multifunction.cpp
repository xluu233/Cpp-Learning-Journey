
// 自定义多个函数使用

#include <iostream>

using namespace std;

double getSum(double a, double b);


int main(){

    double result = getSum(1.0,2.0);

    cout<<result<<endl;

    system("pause");
    return 0;
}

double getSum(double a, double b){
    double c = a + b;
    return c;
}