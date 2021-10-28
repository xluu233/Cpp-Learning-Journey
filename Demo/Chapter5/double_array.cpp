#include <iostream>
using namespace std;

int main(){

    const char* city[4] ={
        "Wuhan","Shanghai","Beijing","哈哈"
    };


    int test[4][5] = {};

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cout << test[i][j] << "   ";
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}