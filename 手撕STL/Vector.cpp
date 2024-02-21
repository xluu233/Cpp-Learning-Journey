//
// Created by xlu on 2023/8/4.
//
#include <iostream>

template<typename T>
class vector
{
private:
    T* data = nullptr;
    int size = 0;
    int capacity = 0;

    inline void checkMemory()
    {
        if(nullptr == this->data)
        {
            capacity = 16;
            size = 0;
            this->data = new T[capacity];
        }
        if (this->size == this->capacity)
        {
            capacity *= 2;
            T* new_data = new T[capacity];
            memcpy(new_data,data,size*sizeof(T));
            delete[] data;
            data = new_data;
        }
    }

public:
    vector() {}

    vector(int size, const T& data)
    {
        this->capacity = size*2;
        this->size = size;
        this->data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = data;
        }
    }

    ~vector()
    {
        clear();
    }

    //拷贝构造函数
    vector(const vector& vec)
    {
        if (data)
        {
            size = 0;
            capacity = 0;
            delete[] data;
            data = nullptr;
        }
        this->capacity = vec.capacity;
        this->size = vec.size;
        this->data = new T[capacity];
        memcpy(this->data,vec.data,this->size*sizeof(T));
    }

    //拷贝赋值
    vector& operator=(const vector<T>& vec)
    {
        this->clear();
        this->capacity = vec.capacity;
        this->size = vec.size;
        this->data = new T[capacity];
        memcpy(this->data,vec.data,this->size*sizeof(T));
        return *this;
    }

    //移动构造函数
    vector(vector<T>&& vec)
    {
        this->capacity = vec.capacity;
        this->size = vec.size;
        this->data = vec.data;
        vec.size = 0;
        vec.capacity = 0;
        vec.data = nullptr;
    }

    vector& operator=(vector<T>&& vec)
    {
        this->clear();
        this->capacity = vec.capacity;
        this->size = vec.size;
        this->data = vec.data;
        vec.size = 0;
        vec.capacity = 0;
        vec.data = nullptr;
        return *this;
    }

    //插入元素到队尾
    void push_back(const T& t)
    {
        checkMemory();
        data[size] = t;
        size++;
    }

    //删除最后一个元素
    void pop_back()
    {
        if (size > 1)
        {
            data[size] = 0;
            size--;
        }
    }

    //插入元素到index
    void insert(const int index, const T& t)
    {
        if (index >= 0 && index <= this->size)
        {
            checkMemory();

            for (int i = size; i > index ; --i) {
                this->data[i] = this->data[i-1];
            }
            this->data[index] = t;
            this->size++;
        }
    }

    //删除元素
    void erase(int index)
    {
        if (index >= 0 && index < this->size)
        {
            for (int i = index; i < size ; ++i) {
                this->data[i] = this->data[i+1];
            }
            this->data[size] = 0;
            this->size--;
        }
    }


    //清除vector
    void clear()
    {
        if (nullptr != data)
        {
            delete[] data;
        }
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    T& operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return this->data[index];
        }
    }

    void print()
    {
        std::cout << "vector size:" << size << "  capacity:" << capacity << std::endl;
        if (data)
        {
            for (int i = 0; i < size; ++i) {
                std::cout << data[i] << " - ";
            }
            std::cout << std::endl;
        }
    }

};

int main()
{
    using namespace std;

    vector<int> vec;
    vec.push_back(1);
    vec.print();

    //移动
    vector<int> vec1 = std::move(vec);
    vec1.print();

//    vector<int> vec2(vec1);
//    vec2.print();
//
//    vector<int> vec3 = vec1;
//    vec3.print();


    for (int i = 2; i < 20; ++i) {
        vec1.push_back(i);
    }
    vec1.print();


    //ok!!
    vec1.erase(3);
    vec1.print();

    vec1.insert(3,4);
    vec1.print();

    //delete!!
    vec1.clear();
    vec1.print();

}