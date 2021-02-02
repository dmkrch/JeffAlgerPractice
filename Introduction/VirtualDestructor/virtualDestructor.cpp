#include <stdio.h>

class Foo
{
public:
    Foo() {}
    ~Foo() { printf("Foo\n"); }
};

class Bar : public Foo
{
private:
    int* numbers;
public:
    Bar() : numbers(new int[17]) { }

    ~Bar() { printf("Bar\n"); }
};

int main()
{    
    Foo* f = new Bar();
    delete f;       // oups! calls Foo::Foo()
    // and that causes int* numbers not to be deleted
    // how to fix? make both destructors virtual

    return 1;
}