#include <iostream>
#include <memory>
using namespace std;

struct A;
struct B;

struct A {
    weak_ptr<B> pointer;
    ~A() {
        cout << "A destroyed" << std::endl;
    }
};
struct B {
    weak_ptr<A> pointer;
    ~B() {
        cout << "B destroyed" << std::endl;
    }
};

void test1()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->pointer = b;
    b->pointer = a;

    cout << "a.use_count()  =  " << a.use_count() << endl;
    cout << "b.use_count()  =  " << b.use_count() << endl;

    cout << a->pointer.expired() << endl;
    cout << b->pointer.expired() << endl;

}

void checkwp(weak_ptr<string>& wp)
{
    //检查wp管理的sp是否有效
    if (!wp.expired())
    {
        //lock方法用来获取原始sp指针
        auto sp = wp.lock();
        std::cout << *sp << std::endl;
    }
    else
    {
        std::cout << "wp expired" << std::endl;
    }
}


void test2()
{
    shared_ptr<string> sp1 = make_shared<string>("bug maker!");

    //不同的构造方式
    weak_ptr<string> wp1 = sp1;
    weak_ptr<string> wp2(sp1);
    weak_ptr<string> wp3 = wp2;

    checkwp(wp1);

    //释放sp指针, 这里只是wp1释放了sp指针，wp2和wp3还持有sp的指针
    wp1.reset();
    checkwp(wp1);

    //wp2和wp3还持有sp的指针
    checkwp(wp2);

    //原始指针
    std::cout <<  (wp2.lock() == wp3.lock() ? "true" : "false") << std::endl;
    std::cout <<  (sp1 == wp2.lock() ? "true" : "false") << std::endl;

}

int main() {
//    test1();
    test2();
    return 0;
}