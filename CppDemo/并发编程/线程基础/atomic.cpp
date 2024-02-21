#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;


atomic<long> gl;

void add(){
    for (size_t i = 0; i < 1000; i++)
    {
        gl += 1;
    }
}

int main(){

    thread td[10];

    gl = 0;
    std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();

    for (size_t i = 0; i < 10; i++)
    {
        td[i] = thread(add);
    }
    
    for (size_t i = 0; i < 10; i++)
    {
        td[i].join();
    }
    std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();

    cout << "gl: " << gl << endl;

    // std::cout << "当前总数为:" << gl << std::endl;
    // std::cout << "消耗时间为：" << std::chrono::duration_cast<std::chrono::milliseconds> (endTime - startTime).count() <<"毫秒"<< std::endl;

    return 0;
}