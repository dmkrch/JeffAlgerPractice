#include <stdio.h>
#include <iostream>


class Foo
{
private:
    int age;
public:
    Foo(int a) : age(a) {}
    int Value() { return age; }
};

/* class for describing pointer of Foo class */
class PFoo
{
private:
    Foo* foo;
public:
    PFoo() : foo(nullptr) {}
    PFoo(Foo* f) : foo(f) {}
    operator Foo*() { return foo; }
    PFoo operator+(ptrdiff_t offset) { return PFoo(foo + offset); }
    PFoo operator+=(ptrdiff_t offset) { foo += offset; return *this; }
    ptrdiff_t operator-(PFoo pf) { return foo - pf.foo; }
    void operator=(Foo* pointer) { foo = pointer; }
    // and so on, for all the operations with pointers
};

int main()
{
    PFoo pf;
    Foo* foo = new Foo(5);

    printf("%d\n", foo->Value());

    pf = foo;

    /* now our PFoo is actually foo object. We want to call 
       member of this class Value() */

    //printf("%d", pf->Value()); // we get an error

    printf("%d\n", ((Foo*)pf)->Value()); // ok

    // output: 5 5
    return 1;
}