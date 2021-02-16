#include <stdio.h>

class ArrayCursor;

struct Index
{
    int x;
    int y;
    Index(int wx, int wy) : x(wx), y(wy) {}
    bool operator==(const Index& i) { return x == i.x && y == i.y; }
    operator bool() {} // need to convert type Index to bool
};

class Foo
{
private:
    int age;
public:
    Foo(int a) : age(a) {}
    int GetAge() { return age; }
};

class SparseArray
{
friend class ArrayCursor;

private:
    struct Node
    {
        Index index;
        Foo* content;
        Node* next;
        Node(Index i, Foo* c, Node* n) 
            : index(i), content(c), next(n) {}
    };
    Node* cells;
public:
    SparseArray() : cells(NULL) {}
    ArrayCursor operator[](Index i);
};


class ArrayCursor
{
friend class SparseArray;
private:
    SparseArray& array;
    Index index;
    SparseArray::Node* node;

    ArrayCursor(SparseArray& arr, Index i)
        : array(arr), index(i), node(NULL) {}

    ArrayCursor(SparseArray& arr, SparseArray::Node* n)
        : array(arr), node(n), index(n->index) {}

public:
    ArrayCursor& operator=(Foo* foo);
};

ArrayCursor& ArrayCursor::operator=(Foo* foo)
{
    if (node == NULL)
    {
        node = new SparseArray::Node(index, foo, array.cells);
        array.cells = node;
    }
    else
        node->content = foo;
    return *this;
}

ArrayCursor SparseArray::operator[](Index i)
{
    SparseArray::Node* n = cells;
    while(n != NULL)
        if (n->index = i)
            return ArrayCursor(*this, n);
        else
            n = n->next;
        
    return ArrayCursor(*this, i);
}

