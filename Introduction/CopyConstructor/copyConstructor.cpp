#include <stdio.h>
#include <string.h>

class Serialized
{
private:
    static int NextSerialNumber;
    int serialNumber;
public:
    /* copy constructor */
    Serialized(const Serialized&);

    /* default constructor */
    Serialized();

    /* function returns serial number */
    int SerialNumber();
};

/* initializing static variable */
int Serialized::NextSerialNumber = 0;


Serialized::Serialized() : serialNumber(NextSerialNumber++) { }

Serialized::Serialized(const Serialized&) : serialNumber(NextSerialNumber++) { }

int Serialized::SerialNumber() { return serialNumber; }


class Student : public Serialized
{
private:
    char* name;
    int age;
public:
    Student(int age, const char* name)
    {
        this->age = age;
        this->name = strdup(name);
    }

    void PrintID() { printf("%d ", this->SerialNumber()); }
};

int main()
{
    /* so here we create student, by passing arguments to 
    constructor, but before constructor will do things, compiler
    will set up base classes by calling their's default constructors */
    Student st1(25, "Dmitriy");
    Student st2(18, "Anton");
    Student st3(19, "Sasha");

    st1.PrintID();
    st2.PrintID();
    st3.PrintID();
    
    return 0;
}