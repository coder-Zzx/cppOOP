/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class A
{
private:
    int a;
public:
    A(int a=0)
    {
        this->a=a;
    }
    A& operator+(int num)
    {
        this->a+=num;
        return *this;
    }
    virtual void show()
    {
        cout<<"a="<<this->a<<endl;
    }
};

class B:public A
{
private:
    int b;
public:
    B(int num_1=0,int num_2=0):A(num_1)
    {
        this->b=num_2;
    }
    virtual B& operator+(int num)
    {
        this->b+=num;
        return *this;
    }
    void show()
    {
        A::show();
        cout<<"b="<<this->b<<endl;
    }
};

void add(A &a,int x)
{
    a+x;
}
void add(B &b,int x)
{
    b+x;
}

int main()
{
    A myA,*p;
    B myB(2,3);
    add(myA,3);
    p=&myA;
    p->show();
    add(myB,3);
    p=&myB;
    p->show();
    // system("pause");
    return 0;
}
