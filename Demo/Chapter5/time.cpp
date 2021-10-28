#include <ctime>
#include <iostream>
using namespace std;

int main(){

    time_t now = time(0);

    char* dt = ctime(&now);
    
    cout << "time:"<<dt<<endl;


    tm *ltm = localtime(&now);

    // 输出 tm 结构的各个组成部分
    cout << 1900 + ltm->tm_year << endl;
    cout << 1 + ltm->tm_mon<< endl;
    cout <<  ltm->tm_mday << endl;
    cout << 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;

    system("pause");
    return 0;
}