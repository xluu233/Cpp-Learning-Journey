//
// Created by xlu on 2023/10/25.
//
#include <iostream>
#include <mutex>

class Singleton
{
private:
    static Singleton* instance;
    static std::mutex mtx;

public:
    static Singleton* getInstance()
    {
        if (instance == nullptr)
        {
            std::lock_guard<std::mutex> lockGuard(mtx);
            if (instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }

};


Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;