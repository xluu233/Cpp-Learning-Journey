// 基本数据类型展示

#include <iostream>
using namespace std;

int main(){

   
    int i = INT_MAX;
    int i_m = INT_MIN;
    cout << i_m << "~" <<i << endl;

    int i_8 = INT8_MAX;
    int i_8_m = INT8_MIN;
    cout << i_8_m << "~"  << i_8 << endl;

    int i_16 = INT16_MAX;
    int i_16_m = INT16_MIN;
    cout << i_16_m << "~" << i_16 << endl;

    int i_32 = INT32_MAX;
    int i_32_m = INT32_MIN;
    cout  << i_32_m << "~" << i_32 << endl;

    unsigned int i_64 = INT64_MAX;
    unsigned int i_64_m = INT64_MIN;
    cout  << i_64_m << "~" << i_64 << endl;

    cout << "---------------------" << endl;

    //测试取值范围超出的情况
    i++;
    i_m--;
    cout << i_m << "~" <<i << endl;

    cout << "---------------------" << endl;


    //无符号类型呢？
    i_64++;
    i_64_m--;
    cout  << i_64_m << "~" << i_64 << endl;



    system("pause");
    return 0;
}