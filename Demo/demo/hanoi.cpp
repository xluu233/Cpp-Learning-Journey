#include <iostream>

using namespace std;

void hanoi(int n,char A,char B,char C);
void move(char A,char C);


int main(){
    cout<<"input N:";
    int size;
    cin >> size;
    hanoi(size,'A','B','C');

    return 0;
}

void hanoi(int n,char A,char B,char C){
    if(n==1){
        move(A,C);
    }else{
        hanoi(n-1,A,C,B);
        move(A,C);
        hanoi(n-1,B,C,A);
    }
}

void move(char A,char C){
    cout<<"moved:"<<A<<" to "<<C<<endl;
}