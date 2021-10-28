/* Compile code with optimization option */
#include <stdio.h> 
#include <iostream>
using namespace std;

int main(void) 
{ 
    const volatile int local = 10; 
    int *ptr = (int*) &local; 

    printf("Initial value of local : %d \n", local); 

    *ptr = 100; 

    printf("Modified value of local: %d \n", local); 

    static volatile int i = 123;
    const static volatile int j = 123;
    cout<<i<<endl;
    cout<<j<<endl;

    cout<<"-----------------"<<endl;
    int test = 1231321;
    volatile int *ptr = &test;
    cout<<*ptr<<endl;

    return 0; 
} 
