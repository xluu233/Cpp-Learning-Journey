//
// Created by xlu on 2023/8/11.
//
#include<queue>
#include<iostream>
#include <mutex>


using callback = void(*)(void* arg);


class Task
{
private:
    callback fun;
    void* arg;

public:
    Task() : fun(nullptr), arg(nullptr) {}

    Task(callback f,void* arg) : fun(f) ,arg(arg) { }
};

/**
 * 任务队列，使用queue实现
 */
class TaskQueue
{
private:
    std::mutex _mutex;
    std::queue<Task> _queue;

public:
    TaskQueue() {}

    void push(Task& task)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push(task);
    }

    void push(callback f,void* arg)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _queue.push({f,arg});
    }

    Task& get()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        Task t;
        if (_queue.size() != 0)
        {
            t = _queue.front();
            _queue.pop();
        }
        return t;
    }
};