#include <stdio.h>
#include <iostream>

class Foo
{
private:
    int age;
public:
    Foo(int a) : age(a) {}
    int GetAge() { return age; }
};


template <class T>
class SmartP
{
private:
    T* pointer;
public:
    SmartP() : pointer(NULL) {}
    SmartP(T* p) : pointer(p) {}

    operator T*() { return pointer; } // how to converse to T
    T* operator->() { return pointer; }

    SmartP<T> operator+(long id) { return Ptr<T>(pointer+id); }
};


/* accepts Foo*/
void f(Foo*) {}


int main()
{
    SmartP<Foo> fooP(new Foo(5));

    /* trying to converse SP to Foo. But Foo is T in template */
    f(fooP);

    fooP->GetAge(); // works due to overload of ->

    
    /* so now we have base form of smart pointers */

    return 1;
}