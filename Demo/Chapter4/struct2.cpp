#include <iostream>
#include <string.h>
using namespace std;

struct Book
{
    string name;
    int id;
    long int ISBN;
}book1,book2;

typedef struct{
    int id;
    string name;
}Ebook;

struct TBook : public Book
{
    private:
        int ids = 1232342;
    public:
        string names;
        long int TTT;
        void printBook(TBook *book);
}tbook;

void TBook::printBook(TBook *book){
    cout<<book->ids<<endl;
    cout<<book->names<<endl;
    cout<<book->TTT<<endl;

    cout<<book->name<<endl;
}

int main(){

    book1.name = "C++ programing";
    cout<<book1.name<<endl;

    // struct Book book3;
    Book book3{
        "Android++",
        1,
        21321231
    };

    cout<<book3.id<<endl;
    cout<<book3.name<<endl;
    cout<<book3.ISBN<<endl;

    cout << "----------------" <<endl;

    Ebook ebook{
        2,"啊哈哈哈"
    };

    Ebook *ptr_book;
    ptr_book = &ebook;

    cout<< ptr_book->id <<endl;
    cout<< ptr_book->name <<endl;

    cout << "----------------" <<endl;

    tbook.name = "C++";
    tbook.names = "Android++";
    tbook.TTT = 1213;

    tbook.printBook(&tbook);

    system("pause");
    return 0;
}