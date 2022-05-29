/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class Base
{
public:
    Base(int _x)
    {
        this->x=_x;
    }
    void show()
    {
        cout<<"x="<<this->x<<endl;
    }
protected:
    int x;

};

class Derived:public Base
{
private:
    int y;
public:
    Derived(int _x,int _y):Base(_x)
    {
        // this->x=_x;
        this->y=_y;
    }
    void show()
    {
        cout<<"x="<<this->x<<endl;
        cout<<"y="<<this->y<<endl;
    }
};

void func1(Base base)
{
    base.show();
}

void func2(Derived derived)
{
    derived.show();
}

int main()
{
    Derived a(10,20);
    a.show();
    Base* base;
    Derived* derived;
    base=&a;
    derived=&a;
    base->show();
    derived->show();
    func1(a);
    func2(a);
    // system("pause");
    return 0;
}
