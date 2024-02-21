//
// Created by xlu on 2023/3/31.
//

#ifndef CPPDEMO_SAFEQUEUE_H
#define CPPDEMO_SAFEQUEUE_H

#include <queue>
#include <mutex>

/**
 * 实现一个线程安全的队列
 * @tparam T
 */
template <typename T>
class SafeQueue{

private:
    std::queue<T> m_queue;

    std::mutex mt;

public:

    SafeQueue(){}

    SafeQueue(SafeQueue &&safeQueue){}

    ~SafeQueue(){
    }

    bool empty(){
        std::unique_lock<std::mutex> lock(mt);
        return m_queue.empty();
    }

    int size(){
        std::unique_lock<std::mutex> lock(mt);
        return m_queue.size();
    }

    void enqueue(T &t){
        std::unique_lock<std::mutex> lock(mt);
        m_queue.emplace(t);
    }

    bool dequeue(T &t){
        std::unique_lock<std::mutex> lock(mt);
        if (m_queue.empty()){
            return false;
        }
        // 取出队首元素，返回队首元素值，并进行右值引用
        t = std::move(m_queue.front());
        // 弹出入队的第一个元素
        m_queue.pop();
        return true;
    }

};

#endif //CPPDEMO_SAFEQUEUE_H
