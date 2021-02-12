#include <stdio.h>


template <class T>
class MP;


class Foo
{
friend class MP<Foo>;

protected:
    Foo() { printf("Foo constr\n"); } // access to friends of Foo
public:
    void Print() { printf("Print\n"); }
    void Initialize(int age, const char* name) { /* ... */ }
    ~Foo() { printf("Foo destr\n"); }
};



template <class T>
class MP
{
public:
    MP() : t(new T) { printf("MP constr\n"); }
    ~MP() { printf("MP destr\n"); delete t; }
    T* operator->() { return t; }

private:
    T* t;
};



int main()
{ 
    MP<Foo> mp1;    // creating Foo* with allocated memory
    mp1->Initialize(5, "asdff");  // initialize Foo* 
    mp1->Print();

    




    

    return 1;
}