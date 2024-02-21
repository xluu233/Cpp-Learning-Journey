#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <cmath>



using namespace std;


int main(){
    cout << "async test start" << endl;

    int result = 0;
    //async配合lamda表达式
    auto task = async([&result](){
        cout << "thread id: " << this_thread::get_id() << endl;
        for (size_t i = 0; i < 10; i++)
        {
            result += sqrt(i);
            cout << result << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });
    //会阻塞当前线程，并等待task执行完成
    //task.wait();

    cout << "async test end" << endl;
    return 0;
}