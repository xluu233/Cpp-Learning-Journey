#include <iostream>
using namespace std;

#define PI 3.1415926

#define MIN(a,b) (((a)<(b)) ? a : b)


#ifdef NULL
    #define NULL 0
#endif

#ifndef FALSE
    #define FALSE 0
#endif


int main(){
    cout << PI << endl;
    system("pause");
    return 0;
}

// 仅在debug环境执行
#ifdef DEBUG
    //cerr <<"Variable x = " << x << endl;
    cout << "hahah" <<endl;
#endif

#if 0
//    不进行编译的代码
#endif
