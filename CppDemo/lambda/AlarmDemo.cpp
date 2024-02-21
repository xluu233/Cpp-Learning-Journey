//
// Created by A on 2023/6/30.
//

#include <iostream>
#include <chrono>

using Time = std::chrono::steady_clock::time_point;

enum class Sound
{
    Beep,
    Siren,
    Wits
};

using Duration = std::chrono::steady_clock::duration;

/**
 *
 * @param time 报警时间
 * @param sound 声音类型
 * @param duration 间隔
 */
void setAlarm(Time time,Sound sound, Duration duration)
{
    std::cout << "current time:" << std::endl;
};


int main(){

    auto testSound = [](Sound sound){
        using namespace std::chrono;
        //1h 30s c++14支持
        setAlarm(steady_clock::now() + 1h,sound,30s);
    };

    testSound(Sound::Siren);

    int i(0);
    int i1{0};
    int i2 = 0;
    int i3[] = {0,1,2};
    int i4[]{0,1,2,3};
//    int i5[](0,1,2,3);    //error

}