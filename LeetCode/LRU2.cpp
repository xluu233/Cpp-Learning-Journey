//
// Created by xlu on 2023/8/14.
//
#include <iostream>
#include <deque>
#include <unordered_map>

class LRU
{
private:
    int size;
    std::deque<std::pair<int,int>> _deque;
    std::unordered_map<int,std::deque<std::pair<int,int>>::iterator> map;

public:
    LRU(int cap) : size(cap) {}

    int get(int key);

    void put(int key, int value);

    void print()
    {
        for (auto& item : _deque) {
            std::cout << item.first << "-" << item.second << "\t";
        }
        std::cout << std::endl;
    }
};

int LRU::get(int key) {
    //if (map.count(key) > 0)
    if (map.find(key) == map.end())
    {
        std::cout << "key not exist!" << std::endl;
        return -1;
    }
    auto temp = *map[key];
    _deque.erase(map[key]);
    //注意这里是
    _deque.push_front(temp);
    map[key] = _deque.begin();
    return temp.second;
}

void LRU::put(int key, int value) {
    if (map.find(key) == map.end())
    {
        //满了，删除最后一个
        if (size == map.size())
        {
            auto tail = _deque.back();
            map.erase(tail.first);
            _deque.pop_back();
        }
        _deque.push_front({key,value});
        map[key] = _deque.begin();
    }
    else
    {
        //更新值
        _deque.erase(map[key]);
        _deque.push_front({key,value});
        map[key] = _deque.begin();
    }
}


int main()
{
    LRU lru(5);
    for (int i = 0; i < 5; ++i) {
        lru.put(i,i);
    }
    lru.print();

    lru.put(2,2);
    lru.print();


    lru.put(8,8);
    lru.put(10,10);
    lru.print();

}