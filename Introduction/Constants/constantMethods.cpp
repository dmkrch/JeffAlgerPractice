#include <stdio.h>

class foo
{
private:
    int x;
public:
    void f() const; // here variable this
                    // is handled as const this*
                    // so we can't change area of 
                    // memory that is pointed
    void g();
};

void h(int*);
void m(foo*);

void foo::f();
{
    x = 17;     // can't - changing variable of class
    this->g();  // can't - g is a function
    h(&x);      // can't - h can change x 
    m(this);    // can't - not a constant in 'm',
                // while this is constant
}


int main()
{
    return 0;
}