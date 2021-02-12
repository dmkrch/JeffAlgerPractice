#include <stdio.h>

class Foo
{
private:
    int value;
public:
    Foo(int val) : value(val) {}
    int Value() { return value; }
};



template <class T>
class MP
{
public:
    MP() : t(NULL) { printf("constructor\n"); }
    MP(T* pointer) : t(pointer) { printf("contructor\n"); }
    ~MP() { printf("destructor\n"); delete t; }

private:
    T* t;
};



int main()
{ 
    Foo* foo = new Foo(5);
    MP<Foo> mp1(foo);

    /* here we get an error, because two pointers
       point to the same area of memory, and first 
       destructor clears allocated memory, then
       second cant do the same */
    MP<Foo> mp2(foo);


    return 1;
}