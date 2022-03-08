/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class Person
{
private:
    int IdPerson;
    string name,gender,birthday,address;
public:
    Person(int id,string n,string g,string b,string a)
    {
        this->input(id,n,g,b,a);
        this->print();
    }
    void input(int id,string n,string g,string b,string a)
    {
        this->IdPerson=id;
        this->name=n;
        this->gender=g;
        this->birthday=b;
        this->address=a;
    }
    void print()
    {
        cout<<this->IdPerson<<" "<<this->name<<" "<<this->gender<<" "<<this->birthday<<" "<<this->address<<endl;
    }
};

int main()
{
    int id;
    string n,g,b,a;
    while (cin>>id>>n>>g>>b>>a)
    {
        Person *person=new Person(id,n,g,b,a);
        delete person;
        person=NULL;
    }
    // system("pause");
    return 0;
}