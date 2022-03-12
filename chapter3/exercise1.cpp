/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class Student
{
private:
    static float proportion;
public:
    int usual;
    int final;
    Student()
    {
        this->usual=0;
        this->final=0;
    }
    static void setProp()
    {
        cin>>Student::proportion;
    }
    void compScore()
    {   
        cout<<this->usual*this->proportion+this->final*(1.0-this->proportion);
    }
};

class Teacher
{
private:
    Student* stu;
public:
    Teacher(int n)
    {
        this->stu=new Student[n]();
    }
    void assign(int n)
    {
        cin>>stu[n].usual;
        cin>>stu[n].final;
    }
    void show(int n)
    {
        stu[n].compScore();
    }
};

float Student::proportion=0.0;

int main()
{
    Student::setProp();
    int num=0;
    cin>>num;
    Teacher *teacher=new Teacher(num);
    for (int i=0;i<num;i++)
    {
        teacher->assign(i);
        teacher->show(i);
        cout<<" ";
    }
    delete teacher;
    teacher=NULL;
    // system("pause");
    return 0;
}
