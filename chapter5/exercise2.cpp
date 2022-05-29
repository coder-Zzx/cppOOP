/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cstring>
using namespace std;

class A
{
private:
    char* name;
public:
    void show()
    {
        cout<<this->name<<endl;
    }
    A(const char* str)
    {
        this->name=new char[strlen(str)+1];
        strcpy(this->name,str);
    }
    ~A()
    {
        delete[] this->name;
        cout<<"destructor A"<<endl;
    }
    A()
    {
        return;
    }
    virtual void print()
    {
        return;
    }
};

class B:public A
{
private:
    int age;
public:
    void print()
    {
        cout<<"B:";
        this->show();
        cout<<this->age<<endl;
    }
    B(const char* str,int age):A(str),age(age)
    {
        return;
    }
};

class C:public A
{
private:
    char gender;
public:
    void print()
    {
        cout<<"C:";
        this->show();
        cout<<gender<<endl;
    }
    C(const char* str,char g):A(str),gender(g)
    {
        return;
    }
};

class manager
{
private:
    A** array;
    int len;
public:
    manager(int n)
    {
        this->array=new A*[n];
        this->len=0;
    }
    ~manager()
    {
        for (int i=0;i<4;i++)
        {
            delete *(this->array+i);
        }
    }
    void add(int a,const char* name,int age)
    {
        this->array[a]=new B(name,age);
        this->len++;
    }
    void add(int a,const char* name,char g)
    {
        this->array[a]=new C(name,g);
        this->len++;
    }
    void display()
    {
        int i=0,j=0;
        while (true)
        {
            if (this->array[i])
            {
                this->array[i]->print();
                j++;
            }
            i++;
            if (i>this->len)
            {
                break;
            }
        }
    }
};

int main()
{
    manager m(4);
    m.add(0,"zhang",18);
    m.add(1,"wang",'F');
    m.add(3,"liu",'M');
    m.display();
    // system("pause");
    return 0;
}
