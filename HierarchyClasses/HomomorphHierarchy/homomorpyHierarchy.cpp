class Grandpa
{
public:
    virtual void Fn1() = 0;
    virtual void Fn2(int) = 0;
};


class Dad : public Grandpa
{
private:
    // something Dad has never told about
protected:
    // something that Dad had, but Grandad didn't
public:
    virtual void Fn1() {} // we must realise this func
    virtual void Fn2(int) {} // and this as well
};

class AuntMartha : public Grandpa
{
private:
    // personal life of aunt Martha
protected:
    // something that aunt has passed to her children
public:
    virtual void Fn1() {}
    virtual void Fn2(int) {}
};

class Me : public Dad
{
private:
    // my sercret information
protected:
    // something i will pass to children
public:
    virtual void Fn1() {}
    virtual void Fn2(int) {}
};


/* Class is called homomorphy, if it doesn't contain any new
   public func\var, only private\protected. So classes Dad, 
   AuntMarthy, Me are gomomorphy towards to GrandPa */
int main()
{


    return 1;
}