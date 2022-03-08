/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class Student
{
private:
    int number;
    string name;
public:
    int grades;
    Student()
    {
        return;
    }
    void create(string s,int n,int g)
    {
        this->name=s;
        this->number=n;
        this->grades=g;
    }
    void print()
    {
        cout<<this->number<<" "<<this->name<<" "<<this->grades<<endl;
    }
};

Student max(Student* stu,int n)
{
    int max_num=0;
    for (int i=1;i<n;i++)
    {
        if (stu[i].grades>stu[max_num].grades)
        {
            max_num=i;
        }
    }
    return stu[max_num];
}

int main()
{
    int N=0,number=0,grades=0;
    string name=" ";
    cin>>N;
    Student *stu=new Student[N];
    for (int i=0;i<N;i++)
    {
        cin>>number>>name>>grades;
        stu[i].create(name,number,grades);
    }
    Student best_student=max(stu,N);
    best_student.print();
    delete stu;
    stu=NULL;
    // system("pause");
    return 0;
}