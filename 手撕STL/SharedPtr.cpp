//
// Created by xlu on 2023/8/3.
//
#include <iostream>
#include <memory>
#include <atomic>

using namespace std;

class SharedCount
{
public:
    SharedCount() : count(1) {}

    void add()
    {
        count++;
    }

    void minus()
    {
        count--;
    }

    int get() const
    {
        return count;
    }

private:
    std::atomic<int> count;
};

template <typename T>
class SharedPtr{

public:
    SharedPtr() : ptr(nullptr), ref_count(new SharedCount()) {}

    explicit SharedPtr(T* _ptr) : ptr(_ptr), ref_count(new SharedCount()) {}

    SharedPtr(const SharedPtr& _s_ptr)
    {
        this->ptr = _s_ptr.ptr;
        this->ref_count = _s_ptr.ref_count;
        ref_count->add();
    }

    SharedPtr& operator=(const SharedPtr& _s_ptr)
    {
        clean();
        this->ptr = _s_ptr.ptr;
        this->ref_count = _s_ptr.ref_count;
        ref_count->add();
        return *this;
    }

    SharedPtr(SharedPtr&& _s_ptr)
    {
        this->ptr = _s_ptr.ptr;
        this->ref_count = _s_ptr.ref_count;
        _s_ptr.ptr = nullptr;
        _s_ptr.ref_count = nullptr;
    }

    SharedPtr& operator=(SharedPtr&& _s_ptr)
    {
        clean();
        this->ptr = _s_ptr.ptr;
        this->ref_count = _s_ptr.ref_count;
        _s_ptr.ptr = nullptr;
        _s_ptr.ref_count = nullptr;
        return *this;
    }

    T* get() const
    {
        return ptr;
    }

    T& operator* () const
    {
        return  *ptr;
    }

    T* operator-> () const
    {
        return ptr;
    }

    int use_count()
    {
        return ref_count->get();
    }

    ~SharedPtr(){
        clean();
    }

    template<typename U>
    friend class SharedPtr;

    template<typename U>
    SharedPtr(const SharedPtr<U>& up, T* tp)
    {
        this->ptr = tp;
        this->ref_count = up.ref_count;
        ref_count->add();
    }


private:
    T* ptr;
    SharedCount* ref_count;

    void clean()
    {
        if (ref_count)
        {
            ref_count->minus();
            if (ref_count->get() == 0)
            {
                if(ptr) delete ptr;
                delete ref_count;
            }
        }
    }

};

template<typename T, typename U>
SharedPtr<T> static_pointer_cast(const SharedPtr<U>& up)
{
    T* ptr = static_cast<T*>(up.get());
    return SharedPtr(up,ptr);
}


class A
{
public:
    A() { std::cout << "A() \n"; }
    ~A() { std::cout << "~A() \n"; }
};

class B : public A
{
public:
    B() { std::cout << "B() \n"; }
    ~B() { std::cout << "~B() \n"; }
};


void test_shared_ptr()
{
    SharedPtr<size_t> ptr1(new size_t(110));
    cout << ptr1.use_count() << endl;   //1

    {
        SharedPtr<size_t> ptr2 = ptr1;
        cout << ptr1.use_count() << endl;   //2

        SharedPtr<size_t> ptr3(ptr1);
        cout << ptr1.use_count() << endl;   //3

        SharedPtr<size_t> ptr4 = std::move(ptr2);
        cout << ptr4.use_count() << endl;   //3
    }

    cout << ptr1.use_count() << endl;   //1

}

void test_static_cast()
{
//    A* a = new A();
    B* b = new B();
    SharedPtr<B> ptr(b);
    cout << ptr.use_count() << endl;
    {
        SharedPtr<A> ptr_a = static_pointer_cast<A,B>(ptr);
        cout << ptr_a.use_count() << endl;
    }
    cout << ptr.use_count() << endl;
}

int main(){
    test_static_cast();
};
