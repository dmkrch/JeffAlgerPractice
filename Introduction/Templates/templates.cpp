#include <stdio.h>
#include <string.h>

class UnsafeNode
{
private:
    UnsafeNode* next;
    void* data;
public:
    UnsafeNode(void* d, UnsafeNode* n);
    virtual ~UnsafeNode();
    UnsafeNode* Next();
    void* Data();
};

template <class Type>
class SafeNode : private UnsafeNode
{
public:
    SafeNode(Type* d, SafeNode* n) : UnsafeNode(d, n) {}
    virtual ~SafeNode() { delete (Type*)Data(); }
    SafeNode* Next() { return (SafeNode*)UnsafeNode::Next(); }
    Type* Data() { return (Type*)UnsafeNode::Data(); }
};


int main()
{
    // so this node is not safe, because of void*
    // client that uses this class, should cast void*
    // to needed type
    UnsafeNode* head = new UnsafeNode((void*)"Dmitry", nullptr);

    int age = 57;
    SafeNode<int> safeHead(&age, nullptr);

    return 1;
}