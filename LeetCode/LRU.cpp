//
// Created by xlu on 2023/8/13.
//
#include <iostream>
#include <unordered_map>
#include <iterator>

template<typename T>
struct Node
{
    int key;
    T* value;
    Node* pre;
    Node* next;
    Node() : pre(nullptr), next(nullptr), key(0), value(nullptr) { }
    Node(int key, T* value) : pre(nullptr), next(nullptr), key(key), value(value) { }
    ~Node(){
        delete value;
    }
};

template<typename T>
class LruCache
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    std::unordered_map<int,Node<T>*> map;

public:
    LruCache(int size) : size(size) {}

//    ~LruCache()
//    {
//        while (head != nullptr)
//        {
//            auto next = head->next;
//            delete head;
//            head = next;
//        }
//    }


    T* get(int key)
    {
        if (map.count(key))
        {
            Node<T>* node = map.find(key);
            remove(node);
            setHead(node);
            return node->value;
        }
        else
        {
            return nullptr;
        }
    }

    void put(int key, T* value)
    {
        if (map.count(key) > 0)
        {
            Node<T>* node = map[key];
            //更新value的值
            node->value = value;
            //更新Node位置
            remove(node);
            setHead(node);
        }
        else
        {
            //原来的map中没有这个数据，新构建一个
            Node<T>* node = new Node<T>(key,value);

            //map满了，删除不常用的元素
            if (size == map.size())
            {
                map.erase(tail->key);
                remove(tail);
            }

            //更新map
            setHead(node);
            map[key] = node;
        }
    }


    //删除当前元素
    void remove(Node<T>* node)
    {
        if (node == head)
        {
//            auto temp = head->next;
//            delete head;
            head = head->next;
        }
        else if (node == tail)
        {
//            auto temp = head->pre;
//            delete tail;
            tail = head->pre;
        }
        else
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
            //delete node;
        }
    }

    //设置当前元素为头节点
    void setHead(Node<T>* node)
    {
        node->next = head;
        if (head != nullptr)
        {
            head->pre = node;
        }
        head = node;
        if (tail == nullptr)
        {
            tail = head;
        }
    }

    void print()
    {
        auto node = head;
        while (node != nullptr && node->value != nullptr)
        {
            std::cout  << node->key  << " -  " << *(node->value) << "\t\t";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

static const int i = 1;
const static int ii = 2;

int main()
{
    LruCache<std::string> lruCache(5);
    lruCache.put(1,new std::string("AA"));
    lruCache.put(2,new std::string("BB"));
    lruCache.put(3,new std::string("CC"));
    lruCache.put(4,new std::string("DD"));
    lruCache.put(5,new std::string("EE"));
    lruCache.print();

    lruCache.put(4,new std::string("DD"));
    lruCache.put(1,new std::string("AA"));
    lruCache.put(4,new std::string("DD"));
    lruCache.print();


    lruCache.put(6,new std::string("FFFF"));
    lruCache.put(7,new std::string("abc"));
    lruCache.print();

    return 0;
}