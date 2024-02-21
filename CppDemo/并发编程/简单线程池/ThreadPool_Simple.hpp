//
// Created by xlu on 2023/3/31.
//

#ifndef SIMPLETHREADPOOLDEMO_THREADPOOL_HPP
#define SIMPLETHREADPOOLDEMO_THREADPOOL_HPP

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <vector>
#include <condition_variable>

const int MAX_THREAD = 100;

template<typename T>
class ThreadPool_Simple {

public:
    explicit ThreadPool_Simple(int unmber = 1);

    std::queue<T *> task_queue;

    bool append(T *task);

    ~ThreadPool_Simple();

private:
    static void *worker(void *arg);
    void run();

private:
    std::vector<std::thread> work_threads;
    std::mutex queue_mutex;
    std::condition_variable cv;
    bool stop;
};



template <typename T>
ThreadPool_Simple<T>::ThreadPool_Simple(int number)
{
    stop = false;
    if (number <= 0 || number > MAX_THREAD)
    {
        throw "thread size error";
    }
    for (size_t i = 0; i < number; i++)
    {
        std::cout << "created Thread num is : " << i <<std::endl;
        work_threads.emplace_back(worker, this);//添加线程
    }
}

template <typename T>
ThreadPool_Simple<T>::~ThreadPool_Simple()
{
    std::unique_lock<std::mutex> lock(queue_mutex);
    stop = true;

    cv.notify_all();
    for (auto &w : work_threads)
    {
        w.join();
    }

}


template <typename T>
bool ThreadPool_Simple<T>::append(T *task){

    //往任务队列添加任务的时候，要加锁，因为这是线程池，肯定有很多线程
    {
        std::lock_guard<std::mutex> lockGuard(queue_mutex);
        task_queue.push(task);
    }

    //任务添加完之后，通知阻塞线程过来消费任务，有点像生产消费者模型
    cv.notify_one();
    return true;
}


template<typename T>
void *ThreadPool_Simple<T>::worker(void *arg) {
    ThreadPool_Simple *pool = (ThreadPool_Simple*) arg;
    pool->run();
    return pool;
}

template <typename T>
void ThreadPool_Simple<T>::run(){
    while (!stop)
    {
        std::unique_lock<std::mutex> lk(queue_mutex);

        //如果任务队列为空，则停下来等待唤醒
        cv.wait(lk,[&]{
            return !this->task_queue.empty();
        });

        if (!this->task_queue.empty())
        {
            T* request = task_queue.front();
            task_queue.pop();
            if (request)
            {
                request->process();
            }

        }
    }
}

#endif //SIMPLETHREADPOOLDEMO_THREADPOOL_HPP
