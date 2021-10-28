#include <iostream>

using namespace std;


int main(){

    // 数组复制
    int arr[10];
    int arr2[10] = {};
    copy(begin(arr2),end(arr2),begin(arr));

    // 数组初始化
    int arr3[3] = {1,2,3};

    int *p;
    p = arr3;
    cout << "p0:" << p[0] << endl;
    cout << "p1:" << p[1] << endl;
    cout << "p2:" << p[2] << endl;
    // 超出范围
    cout << "p3:" << p[3] << endl;

    cout<<"-------------------"<<endl;


    int arr4[3] = {12,123,123324};

    // 数组指针：指向数组的指针
    int (*cp)[3] = &arr4;
    for (size_t i = 0; i < 3; i++)
    {
        cout<<"error usage "<<*cp[i] <<"  success usage "<<(*cp)[i]<<endl;
    }
    


    cout<<"-------------------"<<endl;

    // 指针数组：数组里面的每个原生都是指针
    char *tp[3] = {"asd","as","f"};
    for(auto i:tp){
        cout<<"value:"<<i<<"      address:"<<&i<<endl;
    }

    cout<<"-------------------"<<endl;

    // 无法通过上面方式初始化
    int *ttp[3];
    for (size_t i = 0; i < 3; i++)
    {
        ttp[i] = &arr4[i];
        cout<<"address:"<<ttp[i] << "  value:"<<*ttp[i] << endl;
    }


    system("pause");
    return 0;
}
