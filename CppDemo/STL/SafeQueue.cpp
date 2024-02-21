//
// Created by A on 2023/7/10.
//
#include <memory>
#include <mutex>


template <typename T>
class SafeQueue{

    struct Node{
        std::shared_ptr<T> data;
        std::unique_ptr<Node*> next;
    };

private:
    std::mutex mutex_head;
    std::mutex mutex_back;
    int _size = 0;
    Node* head = nullptr;
    Node* last = nullptr;

public:
    SafeQueue();
    ~SafeQueue();

    //弹出队列第一个元素
    void pop();
    Node* front();

    Node* back();
    void push(Node* node);

    int size(){
        return _size;
    }


};