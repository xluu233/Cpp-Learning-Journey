//
// Created by xlu on 2023/3/31.
//

#ifndef CPPDEMO_THREADPOOL_H
#define CPPDEMO_THREADPOOL_H

#include <thread>
#include <functional>
#include <vector>
#include <future>
#include <condition_variable>
#include "SafeQueue.h"

class ThreadPool {

private:

    bool m_shutdown;

    SafeQueue<std::function<void()>> m_queue;

    std::vector<std::thread> threads;

    std::mutex mt;

    std::condition_variable cv;


private:
    class ThreadWorker{
    private:
        int m_id;
        ThreadPool* pool;

    public:
        ThreadWorker(ThreadPool* pool,int id) : pool(pool), m_id(id){

        }

        void operator()(){
            std::function<void()> func;

            //是否正在去除队列元素
            bool dequeued;

            while (!pool->m_shutdown){
                {
                    //为线程环境加锁，互访问工作线程的休眠和唤醒
                    std::unique_lock<std::mutex> lock(pool->mt);
                    //等待条件变量通知
                    pool->cv.wait(lock, [&]{
                        //如果任务队列不为空，开始执行
                        return !pool->m_queue.empty();
                    });

                    //取出任务队列中的元素
                    dequeued = pool->m_queue.dequeue(func);
                }
                // 如果成功取出，执行工作函数
                if (dequeued)
                    func();
            }
        }
    };

public:
    ThreadPool(int thread_num = 4) : threads(std::vector<std::thread>(thread_num)),m_shutdown(false)
    {
        init();
    }

    ThreadPool(const ThreadPool &) = delete;

    ThreadPool(ThreadPool &&) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&) = delete;

    void init(){
        for (int i = 0; i < threads.size(); ++i) {
            threads[i] = std::thread(ThreadWorker(this,i));
        }
    }

    void shutdown(){
        m_shutdown = true;
        cv.notify_all();

        for (int i = 0; i < threads.size(); ++i) {
            if (threads[i].joinable()){
                threads[i].join();
            }
        }
    }

    template <typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))>
    {
        // Create a function with bounded parameter ready to execute
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...); // 连接函数和参数定义，特殊函数类型，避免左右值错误

        // Encapsulate it into a shared pointer in order to be able to copy construct
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        // Warp packaged task into void function
        std::function<void()> warpper_func = [task_ptr]()
        {
            (*task_ptr)();
        };

        // 队列通用安全封包函数，并压入安全队列
        m_queue.enqueue(warpper_func);

        // 唤醒一个等待中的线程
        cv.notify_one();

        // 返回先前注册的任务指针
        return task_ptr->get_future();
    }


};


#endif //CPPDEMO_THREADPOOL_H
