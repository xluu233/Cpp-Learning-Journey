#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <stack>
#include <algorithm>

// c++20
#include <span>

template<typename T>
void printVec(std::vector<T> vector1)
{
    for (int i = 0; i < vector1.size(); ++i) {
        std::cout << vector1[i] << " - ";
    }
    std::cout << std::endl;
}

using namespace std;
