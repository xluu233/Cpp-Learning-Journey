#include <iostream>
#include <map>
#include <string>
#include <functional>

// 使用结构化绑定，仅用一行函数内代码实现如下函数：

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value>& m, F foo) {
    for (auto& [key, value] : m ) value = foo(key);
}

int main() {
    std::vector<std::vector<int>> vecSumm;

    std::map<std::string, long long int> m {
        {"a", 1},
        {"b", 2},
        {"c", 3}
    };
    update(m, [](std::string key) -> long long int {
        return std::hash<std::string>{}(key);
    });
    for (auto& [key, value] : m)
        std::cout << key << ":" << value << std::endl;
}

template <typename T> struct DoWork;

template <> struct DoWork<int>;
template <> struct DoWork<float>;

template <typename U> struct DoWork<U*>{

};
