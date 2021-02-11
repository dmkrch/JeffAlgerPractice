#include <stdio.h>

class Action
{
private:
    int age;
public: 
    Action() {}
    Action(int a) : age(a) {}
    void MakeAction() { printf("%d, Action!\n", age); }
};


template <class T>
class SPN
{
private:
    T* pointer;
public:
    SPN() : pointer(NULL) {}
    SPN(T* p) : pointer(p) {}

    operator T*() { return pointer; }
    T* operator->()
    {
        if (pointer == NULL) // error
        {
            fprintf(stderr, "dereferencing NULL!\n");
            pointer = new T;
        }
        return pointer;
    }
};

int main()
{
    /* SIMPLE POINTER */
    Action* actionP = new Action(5);
    actionP = NULL;
    /* here we get an error, because action p is null
       and we try to use selector */
    //actionP->MakeAction();

    /* SMART POINTER */
    SPN<Action> smartActionP;

    /* here we dont get error despite having NULL in 
       smartActionP, because when we use selector, it 
       is overloaded, and controls if p is null, and 
       if so, allocates memory for it */
    smartActionP->MakeAction();


    /* output:
       dereferencing NULL!
       0, Action! 
    */

    return 1;
}