#include <iostream>
#include <thread>


#if !defined(TIME)
#define TIME


std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();

using Time = std::chrono::system_clock::time_point;

#endif // TIME


