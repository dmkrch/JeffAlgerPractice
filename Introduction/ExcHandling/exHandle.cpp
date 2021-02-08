#include <stdio.h>


/* example 1 - dynamic exception specification
   btw it's forbidden from c++ 11 */
enum Gotcha { kTooLow, kTooHigh };

void f1(); // can throw any exceptions

void f2(int x) throw(Gotcha); // can throw Gotcha exceptions

void f3() throw(); // can't throw any exceptions

// void f3() throw(Gotcha); - can't. Actually the same function 


void f2(int x) throw(Gotcha)
{
    if (x < 0)
        throw kTooLow; // func ends here
    if (x > 1000)
        throw kTooHigh; // or there
    
    // do smth..
    printf("work!");
}



int main()
{  

    return 1;
}