#include <stdio.h>
#include <string.h>
#include <stdlib.h>


class Dollar
{
public:
    Dollar(int dollars = 0) : _dollars(dollars) {}

    operator int() { return _dollars; }
 

    int getDollars() { return _dollars; }
    void setDollars(int dollars) { _dollars = dollars; }

private:
    int _dollars;
};



class Cent
{
public:
    Cent(int cents = 0) : _cents(cents) {}

    operator Dollar() { return Dollar(_cents / 100); }

private:
    int _cents;
};



void printInt(int value)
{
    printf("%d", value);
}

void printDollars(Dollar dollars)
{
    printInt(dollars); // here we cast dollar to int,
    // so operator int is called
    printf("$");
}



int main()
{
    Dollar dol1(5);
    printInt(dol1); // prints 5
    printf("\n");

    int d = static_cast<int>(dol1);
    printInt(d);   // prints 5
    printf("\n");


    Cent cent1(2000);
    /* here when we pass Cent to function, 
    it exspects Dollar, so operator Dollar is called,
    then in operator we return new object Dollar, which
    then is being passed to function */
    printDollars(cent1);   // prints 20$
    return 1;
}