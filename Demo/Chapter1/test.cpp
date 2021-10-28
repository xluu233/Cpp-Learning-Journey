
// 如何使用输入输出已经命名空间


#include <iostream>

int main(){
    std::cout << "test" << std::endl;



    int i = std::cin.get();

    std::cout << (int)i << std::endl;


    system("pause");
    return 0;
}