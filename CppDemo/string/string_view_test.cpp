//
// Created by xlu on 2023/8/17.
//
#include <iostream>
#include <string_view>
#include <string>
#include <chrono>
#include <utility>

/**
 * string_view是字符串视图，通过原始字符串指针和偏移地址来管理字符串，
 * 和string不同的是减少拷贝操作，效率比string高很多，可以参考test()方法
 * 优点：用来只显示的时候，效率比string高
 * 缺点：由于string_view只是管理原始指针，当原始指针被删除的时候，会导致未定义行为...
 */


//计时器
class Timer
{
private:
    std::string title;
    std::chrono::high_resolution_clock::time_point m_start, m_stop;
public:
    Timer(std::string  title): title(std::move(title))
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        stop();
    }

    void stop()
    {
        m_stop = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start);
        std::cout << title << " " << (ms.count()) * 0.001 << "s\n";
    }
};

void FunctionWithString(const std::string& string)
{
}

void FunctionWithString(const std::string_view& stringView)
{
}


void test()
{
    {
        Timer timer("std::string");
        for (int i = 0; i < 1000000; i++)
        {
            std::string name = "Yang Xunwu";
            std::string firstName = name.substr(0, 4);
            std::string lastName = name.substr(4, 9);
            FunctionWithString(firstName);
            FunctionWithString(lastName);
        }
    }

    {
        Timer timer("std::string_view");
        for (int i = 0; i < 1000000; i++)
        {
            const char* name = "Yang Xunwu";
            std::string_view firstName = std::string_view(name, 4);
            std::string_view lastName = std::string_view(name + 4, 9);
            FunctionWithString(firstName);
            FunctionWithString(lastName);
        }
    }

//std::string 0.034s
//std::string_view 0.002s

}


int main()
{
    test();


    const char* cstr = "bugmaker";
    std::string_view stringView1(cstr);
    std::string_view stringView2(cstr, 3);
    std::cout << "stringView1: " << stringView1 << ", stringView2: " << stringView2 << std::endl;

    std::string str = "bugmaker";
    std::string_view stringView3(str.c_str());
    std::string_view stringView4(str.c_str(), 3);
    std::cout << "stringView3: " << stringView1 << ", stringView4: " << stringView2 << std::endl;

}