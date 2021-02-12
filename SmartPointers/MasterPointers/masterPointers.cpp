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
    MP();  //creates object
    MP(const MP<T>&); // copies object
    ~MP();  // deletes object

    MP<T>& operator=(const MP<T>&);
    T* operator->() const;

private:
    T* t;
};

template <class T>
MP<T>::MP() : t(new T)
{}

template <class T>
MP<T>::MP(const MP<T>& mp) : t(new Type(*(mp.t)))
{}

template <class T>
MP<T>::~MP()
{
    delete t;
}

template <class T>
MP<T>& MP<T>::operator=(const MP<T>& mp)
{
    if (this != &mp)
    {
        delete t;
        t = new T(*(mp.t));
    }
    return *this;
}

template <class T>
T* MP<T>::operator->() const
{
    return t;
}





int main()
{ 
    MP<Foo> mp1;    // creating Foo* with allocated memory
    mp1->Initialize(5, "asdff");  // initialize Foo* 
    mp1->Print();

    
    return 1;
}