#include <iostream>
using namespace std;

int main(){

    int i =0;

    try
    {
        if (i == 0)
        {
            throw "i is 0";
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    system("pause");
    return 0;
}