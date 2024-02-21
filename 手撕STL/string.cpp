//
// Created by xlu on 2023/8/14.
//
#include <iostream>
#include <memory>
#include <cstring>


class string {

private:
    char* data;
    int size;

public:
    string()
    {
        size = 1;
        data = new char[1];
        *data = '\0';
    }

    string(const char* src)
    {
        if (src == nullptr)
        {
            size = 1;
            data = new char[1];
            *data = '\0';
        }
        else
        {
            size = std::strlen(src) + 1;
            data = new char[size];
            std::strcpy(data,src);
        }
    }

    string(const string& str)
    {
        size = std::strlen(str.data) + 1;
        data = new char[size];
        std::strcpy(data,str.data);
    }

    string(string&& str)
    {
        size = str.size;
        data = str.data;
        str.data = nullptr;
        str.size = 0;
    }

    string& operator=(const string& str)
    {
        if (this == &str)
        {
            return *this;
        }
        if (data)
        {
            delete[] data;
        }
        size = std::strlen(str.data) + 1;
        data = new char[size];
        std::strcpy(data,str.data);
        return *this;
    }

    string& operator=(string&& str)
    {
        if (this == &str)
        {
            return *this;
        }
        if (data)
        {
            delete[] data;
        }
        size = str.size;
        data = str.data;
        str.data = nullptr;
        str.size = 0;
        return *this;
    }

    char* operator*()
    {
        return data;
    }

    ~string()
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }

};

int main()
{
    string str = "abc bugMaker!";
    string str1(str);
    string str2 = str1;

    std::cout << "str:\t" << *str << std::endl;
    std::cout << "str1:\t" << *str1 << std::endl;
    std::cout << "str2:\t" << *str2 << std::endl;


    std::cout  << std::endl;

    string str3 = std::move(str);

    std::cout << "str:\t" << (*str == nullptr) << std::endl;
    std::cout << "str1:\t" << *str1 << std::endl;
    std::cout << "str2:\t" << *str2 << std::endl;
    std::cout << "str3:\t" << *str3 << std::endl;

    return 0;
}