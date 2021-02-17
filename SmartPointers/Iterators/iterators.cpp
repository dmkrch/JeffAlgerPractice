#include <stdio.h>

class Foo
{

};

void f(Foo* arg) {}

/* active iterator */
class Collection
{
public:
    class Iterator
    {
    public:
        bool More() {}
        Foo* Next() {}
    };

    Iterator* Begin() {}
};




int main()
{
    Collection* collection;

    Collection::Iterator* iter = collection->Begin();

    while(iter->More())
        f(iter->Next());

    return 1;
}