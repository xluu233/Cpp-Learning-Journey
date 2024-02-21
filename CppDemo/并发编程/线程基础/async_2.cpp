#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <cmath>



using namespace std;


int main(){
    cout << this_thread::get_id() << endl;
    cout << "async test start" << endl;

    future<int> f1 = async(launch::async,[](){
        cout << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
        return 1;
    });

    future<int> f2 = async(launch::async,[](){
        cout << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        return 1;
    });

    //会阻塞当前线程
//    f1.wait();
//    f2.wait();

//    cout << "f1.get()\t" << f1.get() << endl;
//    cout << "f2.get()\t" << f2.get() << endl;

    cout << "async test end" << endl;
    return 0;
}