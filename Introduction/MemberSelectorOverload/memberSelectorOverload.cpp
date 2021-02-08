#include <stdio.h>


class Foo
{
public:
    void MemberOfFoo() { printf("Foo!\n"); }
};


class Pointer
{
private:
    Foo* f;
public:
    Pointer(Foo* foo) : f(foo) {}
    Foo* operator->() const { return f; }
};

class Pointer2
{
private:
    Pointer p;
public:
    Pointer2(Foo* foo) : p(foo) {}
    Pointer operator->() const { return p; }
};




int main()
{
    Pointer2 p1(new Foo);
    p1->MemberOfFoo();

    // 1. Pointer2::operator-> returns Pointer
    // 2. Pointer::operator-> returns Foo
    // 3. Foo-> is helded like base operator, so it just returns object
    //   and then calls a function


    // p1->MemberOfFoo() --- (Pointer)p->MemberOfFoo() --- (F)


    // output : Foo! Foo!
    return 1;
}