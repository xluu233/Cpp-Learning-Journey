#include <iostream>
#include "ThreadPool_Simple.hpp"

using namespace std;

class Task {
public:
    Task() {

    };

    void process()  {

//        cout << this_thread::get_id << "  task successful!" << endl;
//        std::this_thread::sleep_for(std::chrono::microseconds(100));
//        return;

        while (true) {
            cout << "thread init :" << this_thread::get_id << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

    };

    ~Task() {

    };
};


int main() {


//    ThreadPool_Simple<Task> *thread_pool = new ThreadPool_Simple<Task>(10);
    ThreadPool_Simple<Task> thread_pool(10);
//    return 0 ;
    while (true)
    {
        Task *task = new Task();
        thread_pool.append(task);
//        cout<<"添加的任务数量： "<< thread_pool.task_queue.size()<<endl;
        delete task;
    }

    return 0;
}