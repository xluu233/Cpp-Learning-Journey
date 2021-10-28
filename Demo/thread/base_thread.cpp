#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

#define THREAD_NUMS 5

mutex mut;
void say_hello(int i){
    mut.lock();
    cout << "hello thread:"<< i <<endl;
    mut.unlock();
}

int main(){

    
    thread tids[THREAD_NUMS];
    for (size_t i = 0; i < THREAD_NUMS; i++)
    {
        tids[i] = thread(say_hello,i);
    }
    
    for(auto &th : tids){
        th.join();
    }


    system("pause");
    return 0;
}