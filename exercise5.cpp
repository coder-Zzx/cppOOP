#include<iostream>
using namespace std;

class Student
{
private:
    char* name;
public:
    float g1,g2;
    Student(char* name)
    {
        this->name=name;
        cout<<"construct"<<" "<<name<<endl;
    }
    Student(const Student &stu)
    {
        this->name="liu";
        this->g1=80.0;
        this->g2=70.0;
        cout<<"copy"<<" "<<this->name<<endl;
    }
    
    ~Student()
    {
        cout<<"destruct"<<" "<<this->name<<endl;
    }
    float Getg1()
    {
        return this->g1;
    }
    float Getg2()
    {
        return this->g2;
    }
    Student* GetAddress()
    {
        return this;
    }
};

void GetAvarage(Student stu[])
{
    cout<<(stu[0].g1+stu[0].g2)/2.0<<" ";
    cout<<(stu[1].g1+stu[1].g2)/2.0<<endl;
}

char* a_name="li";
Student a=Student(a_name);

void func()
{
    Student st[2]{Student("zhang"),Student("wang")};
    st[0].g1=80.0;
    st[0].g2=70.0;
    st[1].g1=90.0;
    st[1].g2=80.0;
    GetAvarage(st);
}

int main()
{
    a.g1=90.0;
    a.g2=80.0;
    func();
    Student b=Student(a);
    Student *address_1=&b;
    Student *address_2=b.GetAddress();
    cout<<address_1-address_2<<endl;
    // system("pause");
    return 0;
}