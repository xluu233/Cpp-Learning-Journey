#include <iostream>
#include <string>

using namespace std;


class People
{
private:
    int id;
public:
    string name;
    People(const char* name, int id){
        this->name = name;
        this->id = id;
    }

    virtual void display(){
        cout << "People:" << name << "   created" << endl;
    }
    
    //���麯��������People���ǳ�����
    virtual void test() = 0;
    
    //�������������һ�㶼���麯��
    virtual ~People(){
        cout << "people: " << name << "destoryed" << endl;
    };
};


class Manager : public People
{
private:
    int age;
    int days;
    int weeklySalary;
public:
    Manager(const char* name, int id, int age, int workDays) : People(name,id){
        this->age = age;
        this->days = workDays;
        this->weeklySalary = (days*7*100);
    }

    virtual void display(){
        cout << "Magage:" << name << "   salary" << weeklySalary << endl;
    }
    
    // ������Ҫʵ�ָ���ĳ��󷽷��������ʵ�֣���ʾ���������ǳ�����
    void test(){

    }

    ~Manager(){
        cout << "manager: " << name << "destoryed" << endl;
    }
};

// Magage:�ž���   salary4900
// saler:С���������   salary1680
// saler: С���������destoryed
// people: С���������destoryed
// manager: �ž���destoryed
// people: �ž���destoryed


// Magage:�ž���   salary4900
// saler:С���������   salary1680
// saler: С���������destoryed
// people: С���������destoryed
// manager: �ž���destoryed
// people: �ž���destoryed


class SaleWorker : public People
{
private:
    int profit;
    int salary;
public:
    SaleWorker(const char* name, int id, int profit, int workDays) : People(name,id){
        this->profit = profit;
        this->salary = profit*7*workDays;
    }

    virtual void display(){
        cout << "saler:" << name << "   salary" << salary << endl;
    }

    // ������Ҫʵ�ָ���ĳ��󷽷��������ʵ�֣���ʾ���������ǳ�����
    void test(){
    }

    ~SaleWorker(){
        cout << "saler: " << name << "destoryed" << endl;
    }
};


int main(){

    // �����಻��ʵ����
    // People people("ada",12);

    Manager manager("�ž���",1,30,7);
    SaleWorker saler("С���������",2,24,10);

    People *people;
    people = &manager;
    people->display();

    people = &saler;
    people->display();



    // ��̬ʵ��
    People *people2 = new Manager("XX����",3,30,7);
    people2->display();
    delete people2;

    return 0;
}




