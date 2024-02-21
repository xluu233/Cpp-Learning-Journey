//
// Created by xlu on 2023/3/31.
//
#include <iostream>
#include "ThreadPool.h"

// 添加两个数字的简单函数并打印结果
void multiply(const int a, const int b)
{
//    simulate_hard_computation();
    const int res = a * b;
    printf("thread:%d   res:%d  \n",std::this_thread::get_id(),res);
//    std::cout << a << " * " << b << " = " << res << std::endl;
}

int multiply2(const int a, const int b)
{
    return a+b;
}

int main(){

    ThreadPool threadPool(5);
//    threadPool.init();

    for (int i = 0; i < 10; ++i) {
        threadPool.submit(multiply,i,100);
    }

//    auto future = pool.submit(multiply2, 5, 3);
//    //等待输出完成
//    int res = future.get();
//    std::cout << "Last operation result is equals to " << res << std::endl;

    // 关闭线程池
//    pool.shutdown();

    system("pause");
    return 0;
}
