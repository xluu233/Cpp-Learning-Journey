//
// Created by xlu on 2023/8/12.
//
#include <iostream>

/**
* unique_ptr：
 * 1.没有引用计数
 * 2.禁止拷贝赋值
*/

template<typename T>
class unique_ptr
{
private:
    T* ptr;

    void clean()
    {
        if (ptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }


public:
    unique_ptr() : ptr(nullptr) {}

    unique_ptr(T* ptr) : ptr(ptr) {}


    unique_ptr(unique_ptr& u_ptr) = delete;
    unique_ptr& operator=(unique_ptr& u_ptr) = delete;

    unique_ptr(unique_ptr&& u_ptr)
    {
        this->ptr = u_ptr.ptr;
        u_ptr.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& u_ptr)
    {
        clean();
        this->ptr = u_ptr.ptr;
        u_ptr.ptr = nullptr;
        return *this;
    }

    T* get() const
    {
        return ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    T& operator*() const
    {
        return *ptr;
    }

    ~unique_ptr()
    {
        clean();
    }
};

