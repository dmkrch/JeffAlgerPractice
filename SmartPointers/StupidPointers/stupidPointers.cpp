#include <stdio.h>

/* dynamic exception specification */

class Foo
{
public:
    void MemberOfFoo(){}
};




int main()
{
    Foo* aFoo = new Foo;
    aFoo->MemberOfFoo();


    return 1;
}