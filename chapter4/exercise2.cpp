/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cstring>
using namespace std;

class Base
{
protected:
    char* name;
    int age;
public:
    Base()
    {
        cout<<"Base constructor"<<endl;
    }
    Base(char* name,int age)
    {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->age=age;
        cout<<"Base constructor"<<endl;
    }
    ~Base()
    {
        delete this->name;
        cout<<"Base destructor"<<endl;
    }
    void show()
    {
        cout<<this->name<<" "<<this->age<<" ";
    }
};

class Leader:virtual public Base
{
protected:
    char* occupation;
public:
    Leader(char* name,int age,char occ[]):Base(name,age)
    {
        this->occupation=new char[strlen(occ)+1];
        strcpy(this->occupation,occ);
        cout<<"Leader constructor"<<endl;
    }
    ~Leader()
    {
        delete this->occupation;
        cout<<"Leader destructor"<<endl;
    }
    void show()
    {
        Base::show();
        cout<<this->occupation<<" ";
    }
    void printLeader()
    {
        cout<<this->occupation;
    }
};

class Engineer:virtual public Base
{
protected:
    char* major;
public:
    Engineer()
    {
        cout<<"Engineer constructor"<<endl;
    }
    Engineer(char *name,int age,char maj[]):Base(name,age)
    {
        this->major=new char[strlen(maj)+1];
        strcpy(this->major,maj);
        cout<<"Engineer constructor"<<endl;
    }
    ~Engineer()
    {
        delete this->major;
        cout<<"Engineer destructor"<<endl;
    }
    void show()
    {
        Base::show();
        cout<<this->major;
    }
    void printEngineer()
    {
        cout<<this->major;
    }
};

class Chairman:public Leader,public Engineer
{
public:
    Chairman(char *name,char occ[],char maj[],int age):Base(name,age),Leader(name,age,occ),Engineer(name,age,maj)
    {
        cout<<"Chairman constructor"<<endl;
    }
    ~Chairman()
    {
        cout<<"Chairman destructor"<<endl;
    }
    void show()
    {
        Leader::show();
        Engineer::printEngineer();
        cout<<endl;
    }
};

int main()
{
    Chairman a("Li","chair","computer",20);
    a.show();
    // system("pause");
    return 0;
}
