//
// Created by xlu on 2023/8/11.
//
#include <iostream>

void* memcpy(void *dst, const void *src, size_t size)
{
    if (dst == nullptr || src == nullptr)
        return nullptr;
    char *temp_dst = (char*) dst;
    char *temp_src = (char*) src;

    if (temp_dst > temp_src && temp_dst < temp_src+size)
    {
        //内存重叠,自后向前拷贝
        temp_dst = temp_dst+size-1;
        temp_src = temp_src+size-1;
        while (size--)
        {
            *temp_dst-- = *temp_src--;
        }
    }
    else
    {
        //正常拷贝，从前往后
        while (size--)
        {
            *temp_dst++ = *temp_src++;
        }
    }
    return (void*) dst;
}

char * strcpy(char* dst, const char* src)
{
    if (dst == nullptr || src == nullptr)
        return nullptr;
    char* res = dst;
    while (*dst != '\0')
    {
        *dst++ = *src++;
    }
    return res;
}

int main()
{
    char* dst = new char[10];
    char* src = "123456";
//    strcpy(dst,src);
    memcpy(dst,src,sizeof(char) * 6 );
    std::cout << "src:" << src <<std::endl;
    std::cout << "dst:" << dst <<std::endl;

    delete[] dst;
}